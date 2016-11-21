#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Sorting {
 public:
  string className;
  virtual vector<string> sort(vector<string> arrayString) = 0;
  void swap(vector<string> &arrayString, int from, int to) {
    string swapS = arrayString[from];
    arrayString[from] = arrayString[to];
    arrayString[to] = swapS;
  };
};
