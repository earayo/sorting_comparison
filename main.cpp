#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <time.h>
#include "HandlerFile.cpp"
#include "Sorting.h"
#include "BubbleSort.cpp"
#include "HeapSort.cpp"

using namespace std;

/*
Take n elements from a string's array.
*/
vector<string> take(vector<string> stringArray, int n) {
  vector<string> newArray(n);
  for(int i=0; i<n; i++) {
    newArray[i] = stringArray[i];
  }
  return newArray;
}

/*
Sort a string array and takes the time used for this purpose
*/
vector<string> sort(Sorting& sorting, vector<string> stringArray) {
  clock_t startT, finishT;
  startT = clock();
  vector<string> sortingArray = sorting.sort(stringArray);
  finishT = clock();
  printf("Time Used by %s sort method in %d elements = %4.4f Sec.\n", sorting.className.c_str(), (int) stringArray.size(), (finishT - startT) / (double) CLOCKS_PER_SEC);
  return sortingArray;
}

/*
Create files by every 10000 elements using any sorting method.
 */
void createFileBySortMethod(Sorting& sorting, vector<string> stringArray) {
  int sizeArray = stringArray.size();
  printf("Start Method implemented: %s.\n", sorting.className.c_str());
  for(int i=10000; i < sizeArray; i+=10000) {
    vector<string> arrayToSort = take(stringArray, i);
    vector<string> arraySorted = sort(sorting, arrayToSort);
    char *fileName = const_cast<char*>(string("").c_str());
    sprintf(fileName, "%s_%d.txt", sorting.className.c_str(), i);
    arrayStringToFile(arraySorted, fileName);
  }
  printf("Finish Method implemented: %s.\n", sorting.className.c_str());
}

int main() {
  MAX_CHARS_PER_LINE = 30;
  vector<string> words = readFileToStringArray("palabras.es");
  Bubble bubble;
  createFileBySortMethod(bubble, words);
}
