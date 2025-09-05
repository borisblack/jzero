#ifndef TYPEINFO_H
#define TYPEINFO_H

#include <memory>
#include <vector>
#include "c.h"

class SymTab;
class Parameter;

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
  CLASS_TYPE
};

class TypeInfo {
public:
  const BaseType basetype;
  TypeInfo(const BaseType basetype) : basetype(basetype) {}  
  TypeInfo(const TypeInfo &ob) : basetype(ob.basetype) {}
  virtual ~TypeInfo() = default;
  virtual TypeInfo *clone() = 0;
  virtual const char *str() = 0;
};

class VoidType : public TypeInfo {
public:
  VoidType() : TypeInfo(VOID_TYPE) {}
  VoidType(const VoidType &ob) : TypeInfo(ob) {}
  ~VoidType() = default;
  VoidType *clone () { return new VoidType(*this); }
  const char *str() { return "void"; }
};

class IntType : public TypeInfo {
public:
  IntType() : TypeInfo(INT_TYPE) {}
  IntType(const IntType &ob) : TypeInfo(ob) {}
  ~IntType() = default;
  IntType *clone () { return new IntType(*this); }
  const char *str() { return "int"; }
};

class DoubleType : public TypeInfo {
public:
  DoubleType() : TypeInfo(DOUBLE_TYPE) {}
  DoubleType(const DoubleType &ob) : TypeInfo(ob) {}
  ~DoubleType() = default;
  DoubleType *clone () { return new DoubleType(*this); }
  const char *str() { return "double"; }
};

class StringType : public TypeInfo {
public:
  StringType() : TypeInfo(STRING_TYPE) {}
  StringType(const StringType &ob) : TypeInfo(ob) {}
  ~StringType() = default;
  StringType *clone () { return new StringType(*this); }
  const char *str() { return "String"; }
};

class BoolType : public TypeInfo {
public:
  BoolType() : TypeInfo(BOOL_TYPE) {}
  BoolType(const BoolType &ob) : TypeInfo(ob) {}
  ~BoolType() = default;
  BoolType *clone () { return new BoolType(*this); }
  const char *str() { return "boolean"; }    
};

class NullType : public TypeInfo {
public:
  NullType() : TypeInfo(NULL_TYPE) {}
  NullType(const NullType &ob) : TypeInfo(ob) {}
  ~NullType() = default;
  NullType *clone () { return new NullType(*this); }
  const char *str() { return "null"; }    
};

class NaType : public TypeInfo {
public:
  NaType() : TypeInfo(NA_TYPE) {}
  NaType(const NullType &ob) : TypeInfo(ob) {}
  ~NaType() = default;
  NaType *clone () { return new NaType(*this); }
  const char *str() { return "n/a"; }    
};

class ArrayType : public TypeInfo {
public:
  std::shared_ptr<TypeInfo> elementType;
  ArrayType(std::shared_ptr<TypeInfo> elementType);
  ArrayType(const ArrayType &ob);
  ~ArrayType();
  ArrayType *clone () { return new ArrayType(*this); }
  const char *str();
};

class MethodType : public TypeInfo {
public:
  std::shared_ptr<TypeInfo> returnType;
  std::vector<std::shared_ptr<TypeInfo>> *params = nullptr;
  MethodType(std::shared_ptr<TypeInfo> returnType, std::vector<std::shared_ptr<TypeInfo>> *params);
  MethodType(const MethodType &ob);
  ~MethodType();
  MethodType *clone () { return new MethodType(*this); }
  const char *str();
};

class ClassType : public TypeInfo {
public:
  const char *name;
  SymTab *st = NULL;
  uint nfields = 0;
  Parameter **fields = NULL;
  uint nmethods = 0;
  Parameter **methods = NULL;
  uint nconstrs = 0;
  TypeInfo **constrs = NULL;
  ClassType(const char *name, SymTab *st, uint nfields, Parameter **fields, uint nmethods, Parameter **methods);
  ClassType(const char *name, SymTab *st) : ClassType(name, st, 0, NULL, 0, NULL) {}
  ClassType(const char *name) : ClassType(name, NULL) {}
  ClassType(const ClassType &ob);
  ~ClassType();
  ClassType *clone () { return new ClassType(*this); }
  const char *str() { return name; }
};

class Parameter {
public:
  const char *name;
  std::shared_ptr<TypeInfo> paramType;
  Parameter(const char *name, std::shared_ptr<TypeInfo> paramType);
  Parameter(const Parameter &ob);
  ~Parameter();
  Parameter *clone () { return new Parameter(*this); }
};

const char *typeinfo_Name(TypeInfo *typeInfo);;

#endif /* TYPEINFO_H */
