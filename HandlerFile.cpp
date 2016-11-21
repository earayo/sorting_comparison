#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int MAX_CHARS_PER_LINE = 255;

vector<string> readFileToStringArray(string fileName) {
  vector<string> words;
  char str[MAX_CHARS_PER_LINE];
  char *fName = const_cast<char*>(fileName.c_str());
  printf("Start Reading file and cast to String \"%s\" \n", fName);
  FILE *rFile = fopen(fName,"r");
  while (fgets(str, MAX_CHARS_PER_LINE, rFile) != NULL) {
    string word = string(str);
    int found =  word.find("\n");
    if (found != string::npos) {
      word.erase(found, 1);
    }
    words.push_back(word);
  }
  fclose(rFile);
  printf("Finish Reading \"%s\" and cast to String[%d] \n", fName, (int) words.size());
  return words;
}

void arrayStringToFile(vector<string> arrayString, string fileName) {
  char* aux;
  int max_array = arrayString.size();
  char *fName = const_cast<char*>(fileName.c_str());
  printf("Creating file \"%s\" \n", fName);
  FILE *wFile = fopen(fName,"w");
  for (int i=0; i < max_array; i++) {
    aux = strdup(arrayString[i].c_str());
    fprintf(wFile,"%s\n",aux); 
  }
  printf("Finish file \"%s\" \n", fName);
  fclose(wFile); 
}
