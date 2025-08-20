#include <memory>
#include <string>

using namespace std;

class Hi {
private:
  int a;
public:
  Hi(int a);
  ~Hi();
  void sayHi(shared_ptr<string> str) const;
};
