#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Bubble: public Sorting {
public:
  Bubble() {
    className = "Bubble";
  }
  vector<string> sort(vector<string> arrayString) {
    vector<string> newArray = arrayString;
    int sizeArray = newArray.size();
    int limitI = sizeArray - 1;
    int limitJ, next;
    string swap;
    for(int i=0; i < limitI; i++) {
      limitJ = limitI - i;
      for(int j=0; j < limitJ; j++) {
	next = j + 1;
	if(newArray[j].compare(newArray[next]) > 0) {
	  this->swap(newArray, j, next);
	}
      }
    }
    return newArray;
  }
};
