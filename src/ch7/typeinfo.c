#include <stdlib.h>
#include <string.h>
#include "typeinfo.h"

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

const ArrayType *typeinfo_CreateArrayType(TypeInfo *elementType) {
  ArrayType *arrayType = malloc(sizeof(ArrayType));
  arrayType->basetype = ARRAY_TYPE;
  arrayType->elementType = elementType;

  return arrayType;
}

const MethodType *typeinfo_CreateMethodType(TypeInfo *returnType, uint nparams, Parameter **params) {
  MethodType *methodType = malloc(sizeof(MethodType));
  methodType->basetype = METHOD_TYPE;
  methodType->returnType = returnType;
  methodType->nparams = nparams;
  methodType->params = params;

  return methodType;
}

const ClassType *typeinfo_CreateClassType(char *name, SymTab *st) {
  ClassType *classType = malloc(sizeof(ClassType));
  classType->basetype = CLASS_TYPE;
  classType->name = name;
  classType->nfields = 0;
  classType->fields = NULL;
  classType->nconstrs = 0;
  classType->constrs = NULL;
  classType->nmethods = 0;
  classType->methods = NULL;
  classType->st = st;

  return classType;
}

TypeInfo *typeinfo_Copy(TypeInfo *typeInfo) {
  if (!typeInfo)
    return NULL;
  
  TypeInfo *newTypeInfo = malloc(sizeof *typeInfo);
  memcpy(newTypeInfo, typeInfo, sizeof *typeInfo);

  return newTypeInfo;
}

const char *typeinfo_Name(TypeInfo *typeInfo) {
  if (!typeInfo)
    return NULL;

  switch (typeInfo->basetype) {
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
      return "array";
    case METHOD_TYPE:
      return "method";
    case CLASS_TYPE:
      return "class";
    default:
      return "unknown";
  }
}

void typeinfo_Free(TypeInfo *typeInfo) {
  if (!typeInfo)
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
        typeinfo_Free((TypeInfo*)methodType->params[i]);
      }
      break;
    case CLASS_TYPE:
      ClassType *classType = (ClassType*)typeInfo;
      for (int i=0; i<classType->nfields; i++) {
        typeinfo_Free((TypeInfo*)classType->fields[i]);
      }
      for (int i=0; i<classType->nconstrs; i++) {
        typeinfo_Free((TypeInfo*)classType->constrs[i]);
      }
      for (int i=0; i<classType->nmethods; i++) {
        typeinfo_Free((TypeInfo*)classType->methods[i]);
      }
      break;
    default:
      break;
  }

  free(typeInfo);
}