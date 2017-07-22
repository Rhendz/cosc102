#include <iostream>
#include <cstring>
using namespace std;

int main() {
  const char word[] = "Hello";
  char a_string[10];

  strcpy(a_string, word);
  cout << a_string << endl;
  return 0;
}
