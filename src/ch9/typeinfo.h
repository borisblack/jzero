#ifndef TYPEINFO_H
#define TYPEINFO_H

#include "c.h"

typedef struct SymTab SymTab;
typedef enum BaseType BaseType;
typedef struct TypeInfo TypeInfo;
typedef struct VoidType VoidType;
typedef struct IntType IntType;
typedef struct DoubleType DoubleType;
typedef struct StringType StringType;
typedef struct BoolType BoolType;
typedef struct NullType NullType;
typedef struct NaType NaType;
typedef struct ArrayType ArrayType;
typedef struct MethodType MethodType;
typedef struct ClassType ClassType;
typedef struct Parameter Parameter;

struct SymTab;

enum BaseType {
  VOID_TYPE,
  INT_TYPE,
  DOUBLE_TYPE,
  STRING_TYPE,
  BOOL_TYPE,
  NULL_TYPE,
  NA_TYPE,
  ARRAY_TYPE,
  METHOD_TYPE,
  CLASS_TYPE,
  PARAMETER_TYPE
};

struct TypeInfo {
  BaseType basetype;
};

struct VoidType {
  BaseType basetype; // VOID_TYPE
};

struct IntType {
  BaseType basetype; // INT_TYPE
};

struct DoubleType {
  BaseType basetype; // DOUBLE_TYPE
};

struct StringType {
  BaseType basetype; // STRING_TYPE
};

struct BoolType {
  BaseType basetype; // BOOL_TYPE
};

struct NullType {
  BaseType basetype; // NULL_TYPE
};

struct NaType {
  BaseType basetype; // NA_TYPE
};


struct ArrayType {
  BaseType basetype; // ARRAY_TYPE
  TypeInfo *elementType;
};

struct MethodType {
  BaseType basetype; // METHOD_TYPE
  TypeInfo *returnType;
  uint nparams;
  TypeInfo **params;
};

struct ClassType {
  BaseType basetype; // CLASS_TYPE
  char *name;
  uint nfields;
  Parameter **fields;
  uint nconstrs;
  TypeInfo **constrs;
  uint nmethods;
  Parameter **methods;
  SymTab *st;
};

struct Parameter {
  BaseType basetype; // PARAMETER_TYPE
  const char *name;
  TypeInfo *paramType;
};

const VoidType *typeinfo_VoidType();
const IntType *typeinfo_IntType();
const DoubleType *typeinfo_DoubleType();
const StringType *typeinfo_StringType();
const BoolType *typeinfo_BoolType();
const NullType *typeinfo_NullType();
const NaType *typeinfo_NaType();

/* Initializes typeinfo registry */
void typeinfo_Init();

const ArrayType *typeinfo_CreateArrayType(TypeInfo *elementType);
const MethodType *typeinfo_CreateMethodType(TypeInfo *returnType, uint nparams, TypeInfo **params);
const ClassType *typeinfo_CreateClassType(char *name, SymTab *st, uint nfields, Parameter **fields, uint nmethods, Parameter **methods);
Parameter *typeinfo_CreateParameter(const char *name, TypeInfo *paramType);
const char *typeinfo_Name(TypeInfo *typeInfo);
void typeinfo_Free(TypeInfo *typeInfo);

#endif /* TYPEINFO_H */
