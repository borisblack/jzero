#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "typeinfo.h"

ArrayType::ArrayType(std::shared_ptr<TypeInfo> elementType) : TypeInfo(ARRAY_TYPE) {
  this->elementType = elementType;
}

ArrayType::~ArrayType() {}

ArrayType::ArrayType(const ArrayType &ob) : TypeInfo(ob) {
  elementType = ob.elementType;
}

const char *ArrayType::str() {
  // char arrayTypeStr[50];
  // sprintf(arrayTypeStr, "array of %s", elementType ? elementType->str() : "undef");
  // return arrayTypeStr;
  return "array";
}

MethodType::MethodType(std::shared_ptr<TypeInfo> returnType, std::vector<std::shared_ptr<TypeInfo>> *params) : TypeInfo(METHOD_TYPE) {
  this->returnType = returnType;
  this->params = params;
}

MethodType::MethodType(const MethodType &ob) : TypeInfo(ob) {
  returnType = ob.returnType;
  if (ob.params) {
    params = new std::vector<std::shared_ptr<TypeInfo>>();

    if (ob.params->size() > 0)
      params->insert(params->end(), ob.params->begin(), ob.params->end());
  }
}

MethodType::~MethodType() {
  if (params) {
    params->clear(); // no need because dtor clears list automatically
    delete params;
  }
}

const char *MethodType::str() {
  // char methodTypeStr[100];
  // sprintf(methodTypeStr, "method %s (", returnType ? returnType->str() : "undef");
  // for (int i=0; i<nparams; i++) {
  //   strcat(methodTypeStr, params[i]->str());
  //   strcat(methodTypeStr, (i < nparams-1) ? "," : ")");
  // }
  // return methodTypeStr;
  return "method";
}

ClassType::ClassType(const char *name, SymTab *st, uint nfields, Parameter **fields, uint nmethods, Parameter **methods) : TypeInfo(CLASS_TYPE) {
  this->name = name;
  this->st = st;
  this->nfields = nfields;
  this->fields = fields;
  this->nmethods = nmethods;
  this->methods = methods;
  this->nconstrs = 0;
  this->constrs = NULL;
}

ClassType::ClassType(const ClassType &ob) : TypeInfo(ob) {
  name = ob.name;
  st = ob.st;
  nfields = ob.nfields;
  nmethods = ob.nmethods;
  nconstrs = ob.nconstrs;

  if (nfields > 0) {
    fields = (Parameter**)calloc(nfields, sizeof(Parameter*));
    for (uint i=0; i<nfields; i++) {
      fields[i] = ob.fields[i];
    }
  }

  if (nmethods > 0) {
    methods = (Parameter**)calloc(nmethods, sizeof(Parameter*));
    for (uint i=0; i<nmethods; i++) {
      methods[i] = ob.methods[i];
    }
  }

  if (nconstrs > 0) {
    constrs = (TypeInfo**)calloc(nconstrs, sizeof(TypeInfo*));
    for (uint i=0; i<nconstrs; i++) {
      constrs[i] = ob.constrs[i];
    }
  }
}

ClassType::~ClassType() {
  for (uint i=0; i<nfields; i++) {
    delete fields[i];
  }
  if (fields)
    free(fields);

  for (uint i=0; i<nmethods; i++) {
    delete methods[i];
  }
  if (methods)
    free(methods);

  for (uint i=0; i<nconstrs; i++) {
    delete constrs[i];
  }
  if (constrs)
    free(constrs);
}

Parameter::Parameter(const char *name, std::shared_ptr<TypeInfo> paramType) {
  this->name = name;
  this->paramType = paramType;
}

Parameter::Parameter(const Parameter &ob) {
  name = ob.name;
  paramType = ob.paramType;
}

Parameter::~Parameter() {}
