#include <iostream>
#include "hi.h"

extern "C" {
  void print_pid();
}

Hi::Hi(int a) {
  this->a = a;
}

Hi::~Hi()
{
}

void Hi::sayHi(shared_ptr<string> str) const {
  cout << *str << endl;
}

int main(int argc, char *argv[]) {
  print_pid();
  Hi hello(4);
  hello.sayHi(make_shared<string>("ahahah"));
}
