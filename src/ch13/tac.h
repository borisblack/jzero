#ifndef TAC_H
#define TAC_H

#include <memory>
#include "c.h"

using namespace std;

class Address {
  public:
    char *region;
    uint32 offset;
    Address(const char *region, uint32 offset);
    Address(const Address &ob);
    ~Address();
    Address *clone() { return new Address(*this); }
    const char *regaddr();
    char *str(char *dest);
    int intgr();
    void print();
};

class Tac {
  public:
    const char *op;
    shared_ptr<Address> op1 = NULL;
    shared_ptr<Address> op2 = NULL;
    shared_ptr<Address> op3 = NULL;
    Tac(const char *op, shared_ptr<Address> op1, shared_ptr<Address> op2, shared_ptr<Address> op3);
    Tac(const char *op, shared_ptr<Address> op1, shared_ptr<Address> op2) : Tac(op, op1, op2, NULL) {}
    Tac(const char *op, shared_ptr<Address> op1) : Tac(op, op1, NULL, NULL) {}
    Tac(const char *op) : Tac(op, NULL, NULL, NULL) {}
    Tac(const Tac &ob);
    Tac *clone() { return new Tac(*this); }
    ~Tac();
    void print();
};

#endif /* TAC_H */