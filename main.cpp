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

int MAX_LINES=247049;

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
  printf("Time Used by %s sort method in %d elements = %4.4f Sec.\n", sorting.className, (int) stringArray.size(), (finishT - startT) / (double) CLOCKS_PER_SEC);
  return sortingArray;
}

int main() {
  MAX_CHARS_PER_LINE = 30;
  vector<string> words = readFileToStringArray("palabras.es");
  vector<string> wordsToSort = take(words, 20000);
  Bubble bubble;
  vector<string> wordsBubble = sort(bubble, wordsToSort);
  arrayStringToFile(wordsBubble, "wordBubble.txt");
  HeapSort heapSort;
  vector<string> wordsHeap = sort(heapSort, wordsToSort);
  arrayStringToFile(wordsHeap, "wordHeap.txt");
}
