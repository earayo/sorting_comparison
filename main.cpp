#include "HandlerFile.cpp"
#include <time.h>

long MAX_LINES=247049;

int main() {
  MAX_CHARS_PER_LINE = 30;
  vector<string> words = castFileToString();
  int max_array = words.size();
  cout << "tam Array = " << max_array << endl;
  arrayStringToFile(words, "word.txt");
}
