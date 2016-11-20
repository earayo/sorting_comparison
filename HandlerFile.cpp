#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int MAX_CHARS_PER_LINE = 255;

vector<string> castFileToString() {
  vector<string> words;
  long counter = 0;
  char str[MAX_CHARS_PER_LINE];
  cout<<"Start Reading file and cast to String[]...\n";
  FILE *rFile = fopen("palabras.es","r");
  while (fgets(str, MAX_CHARS_PER_LINE, rFile) != NULL) {
    string word = string(str);
    int found =  word.find("\n");
    if (found != string::npos) {
      word.erase(found, 1);
    }
    words.push_back(word);
  }
  fclose(rFile);
  cout<<"Finish Reading file and cast to String[]...\n";
  return words;
}

void arrayStringToFile(vector<string> arrayString, string fileName) {
  char* aux;
  int max_array = arrayString.size();
  FILE *wFile = fopen(fileName.c_str(),"w");
  for (int i=0; i < max_array; i++) {
    aux = strdup(arrayString[i].c_str());
    fprintf(wFile,"%s\n",aux); 
  }
  fclose(wFile); 
}
