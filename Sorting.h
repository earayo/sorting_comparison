#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Sorting {
 public:
  char* className;
  virtual vector<string> sort(vector<string> arrayString) const = 0;
};
