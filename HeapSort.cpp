#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class HeapSort: public Sorting {
 
  void heapify(vector<string> &arrayString, int root, int sizeArray);
  void buildHeapArray (vector<string> &arrayString);
  
public:
  HeapSort() {
    className = const_cast<char*>(string("Heap").c_str());
  }
  vector<string> sort(vector<string> arrayString) {
    vector<string> newArray = arrayString;
    this->buildHeapArray(newArray);
    int sizeArrayminusOne = newArray.size() - 1;
    for(int i = sizeArrayminusOne; i > 0; i--) {
      this->swap(newArray, 0, i);
      this->heapify(newArray, 0, i);
    }
    return newArray;
  }
};

void HeapSort::heapify(vector<string> &newArray, int root, int size) {
  int left = 2 * root + 1, largest;
  int right = left + 1;

  if (left < size && newArray[left] > newArray[root]) {
    largest = left;
  } else {
    largest = root;
  }

  if(right < size && newArray[right] > newArray[largest]) {
    largest = right;
  }
    
  if(largest != root) {
    this->swap(newArray, root, largest);
    this->heapify(newArray, largest, size);
  }
}

void HeapSort::buildHeapArray (vector<string> &newArray) {
  int sizeArray = newArray.size();
  int sizeArrayMinusOne = sizeArray - 1;
  for(int i = sizeArrayMinusOne / 2; i >= 0; i--) {
    this->heapify(newArray, i, sizeArray);
  }
}
