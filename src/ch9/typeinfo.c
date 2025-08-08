#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "htable.h"
#include "typeinfo.h"

typedef struct TypeInfoEntry TypeInfoEntry;
typedef struct TypeInfoEntry *TypeInfoEntryNode;

struct TypeInfoEntry {
  HTableNode node;
  TypeInfo *typ;
};

static HTable typeInfoRegistry;

static bool typeinfo_keyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg);
static uint32 typeinfo_hashFunc(const HTableNode* a_, void *arg);
static void* typeinfo_allocFunc(size_t size, void *arg);
static void typeinfo_freeFunc(void* mem, void *arg);

static const VoidType _voidType = {
  .basetype = VOID_TYPE
};

static const IntType _intType = {
  .basetype = INT_TYPE
};

static const DoubleType _doubleType = {
  .basetype = DOUBLE_TYPE
};

static const StringType _stringType = {
  .basetype = STRING_TYPE
};

static const BoolType _boolType = {
  .basetype = BOOL_TYPE
};

static const NullType _nullType = {
  .basetype = NULL_TYPE
};

static const NaType _naType = {
  .basetype = NA_TYPE
};

const VoidType *typeinfo_VoidType() {
  return &_voidType;
}

const IntType *typeinfo_IntType() {
  return &_intType;
}

const DoubleType *typeinfo_DoubleType() {
  return &_doubleType;
}

const StringType *typeinfo_StringType() {
  return &_stringType;
}

const BoolType *typeinfo_BoolType() {
  return &_boolType;
}

const NullType *typeinfo_NullType() {
  return &_nullType;
}

const NaType *typeinfo_NaType() {
  return &_naType;
}

/* Initializes typeinfo registry */
void typeinfo_Init() {
  htable_create(
    &typeInfoRegistry,
    sizeof(TypeInfoEntry),
    typeinfo_hashFunc,
    typeinfo_keyeqFunc,
    typeinfo_allocFunc,
    typeinfo_freeFunc,
    NULL,
    NULL
  );
}

const ArrayType *typeinfo_CreateArrayType(TypeInfo *elementType) {
  ArrayType *arrayType = malloc(sizeof(ArrayType));
  arrayType->basetype = ARRAY_TYPE;
  arrayType->elementType = elementType;

  TypeInfoEntry newEntry = {
    .typ = (TypeInfo*)arrayType
  };
  bool isNewNode;
  htable_insert(&typeInfoRegistry, (HTableNode*)&newEntry, &isNewNode);

  return arrayType;
}

const MethodType *typeinfo_CreateMethodType(TypeInfo *returnType, uint nparams, TypeInfo **params) {
  MethodType *methodType = malloc(sizeof(MethodType));
  methodType->basetype = METHOD_TYPE;
  methodType->returnType = returnType;
  methodType->nparams = nparams;
  methodType->params = params;

  TypeInfoEntry newEntry = {
    .typ = (TypeInfo*)methodType
  };
  bool isNewNode;
  htable_insert(&typeInfoRegistry, (HTableNode*)&newEntry, &isNewNode);

  return methodType;
}

const ClassType *typeinfo_CreateClassType(char *name, SymTab *st, uint nfields, Parameter **fields, uint nmethods, Parameter **methods) {
  ClassType *classType = malloc(sizeof(ClassType));
  classType->basetype = CLASS_TYPE;
  classType->name = name;
  classType->nfields = nfields;
  classType->fields = fields;
  classType->nconstrs = 0;
  classType->constrs = NULL;
  classType->nmethods = nmethods;
  classType->methods = methods;
  classType->st = st;

  TypeInfoEntry newEntry = {
    .typ = (TypeInfo*)classType
  };
  bool isNewNode;
  htable_insert(&typeInfoRegistry, (HTableNode*)&newEntry, &isNewNode);

  return classType;
}

Parameter *typeinfo_CreateParameter(const char *name, TypeInfo *paramType) {
  Parameter *parameter = malloc(sizeof(Parameter));
  parameter->basetype = PARAMETER_TYPE;
  parameter->name = name;
  parameter->paramType = paramType;

  TypeInfoEntry newEntry = {
    .typ = (TypeInfo*)parameter
  };
  bool isNewNode;
  htable_insert(&typeInfoRegistry, (HTableNode*)&newEntry, &isNewNode);

  return parameter;
}

const char *typeinfo_Name(TypeInfo *typeInfo) {
  if (!typeInfo)
    return NULL;

  switch (typeInfo->basetype) {
    case VOID_TYPE:
      return "void";
    case INT_TYPE:
      return "int";
    case DOUBLE_TYPE:
      return "double";
    case STRING_TYPE:
      return "String";
    case BOOL_TYPE:
      return "boolean";
    case NULL_TYPE:
      return "null";
    case NA_TYPE:
      return "n/a";
    case ARRAY_TYPE:
      // char arrayTypeStr[50];
      // ArrayType *arrayType = (ArrayType*)typeInfo;
      // sprintf(arrayTypeStr, "array of %s", arrayType->elementType ? typeinfo_Name(arrayType->elementType) : "undef");
      // return arrayTypeStr;
      return "array";
    case METHOD_TYPE:
      // char methodTypeStr[100];
      // MethodType *methodType = (MethodType*)typeInfo;
      // sprintf(methodTypeStr, "method %s (", methodType->returnType ? typeinfo_Name(methodType->returnType) : "undef");
      // for (int i=0; i<methodType->nparams; i++) {
      //   strcat(methodTypeStr, typeinfo_Name((TypeInfo*)methodType->params[i]));
      //   strcat(methodTypeStr, (i < methodType->nparams-1) ? "," : ")");
      // }
      // return methodTypeStr;
      return "method";
    case CLASS_TYPE:
      ClassType *classType = (ClassType*)typeInfo;
      return classType->name;
    default:
      return "unknown";
  }
}

void typeinfo_Free(TypeInfo *typeInfo) {
  if (!typeInfo)
    return;

  if (typeInfo == (TypeInfo*)&_voidType ||
    typeInfo == (TypeInfo*)&_intType ||
    typeInfo == (TypeInfo*)&_doubleType ||
    typeInfo == (TypeInfo*)&_stringType ||
    typeInfo == (TypeInfo*)&_boolType ||
    typeInfo == (TypeInfo*)&_nullType ||
    typeInfo == (TypeInfo*)&_naType)
    return;

  switch (typeInfo->basetype) {
    case ARRAY_TYPE:
      ArrayType *arrayType = (ArrayType*)typeInfo;
      typeinfo_Free(arrayType->elementType);
      break;
    case METHOD_TYPE:
      MethodType *methodType = (MethodType*)typeInfo;
      typeinfo_Free(methodType->returnType);
      for (int i=0; i<methodType->nparams; i++) {
        typeinfo_Free(methodType->params[i]);
      }
      free(methodType->params);
      break;
    case CLASS_TYPE:
      ClassType *classType = (ClassType*)typeInfo;
      for (int i=0; i<classType->nfields; i++) {
        typeinfo_Free((TypeInfo*)classType->fields[i]);
      }
      free(classType->fields);
      for (int i=0; i<classType->nconstrs; i++) {
        typeinfo_Free(classType->constrs[i]);
      }
      free(classType->constrs);
      for (int i=0; i<classType->nmethods; i++) {
        typeinfo_Free((TypeInfo*)classType->methods[i]);
      }
      free(classType->methods);
      break;
    default:
      break;
  }

  TypeInfoEntry searchingEntry = {
    .typ = typeInfo
  };
  if (htable_find(&typeInfoRegistry, (HTableNode*)&searchingEntry)) {
    free(typeInfo);
    htable_delete(&typeInfoRegistry, (HTableNode*)&searchingEntry);
  }
}

/* Typeinfo entry compare func */
static bool typeinfo_keyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg) {
	TypeInfoEntryNode a = (TypeInfoEntryNode)a_;
	TypeInfoEntryNode b = (TypeInfoEntryNode)b_;
	return a->typ == b->typ;
}

/* Typeinfo entry hash func */
static uint32 typeinfo_hashFunc(const HTableNode* a_, void *arg) {
	TypeInfoEntryNode a = (TypeInfoEntryNode)a_;
	return (ulong)a->typ;
}

/* Typeinfo entry alloc func */
static void* typeinfo_allocFunc(size_t size, void *arg) {
	return malloc(size);
}

/* Typeinfo entry free func */
static void typeinfo_freeFunc(void* mem, void *arg) {
	free(mem);
}