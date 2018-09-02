// understanding references
// ref3.cpp

#include <iostream>

using namespace std;

void swap (char *&str1, char *&str2) {
  char *tmp = str1;
  str1 = str2;
  str2 = tmp;
}

int main () {
  char *str1 = "kay";
  char *str2 = "dot";
  swap(str1, str2);
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  return 0;
}

/*
ref3.cpp: In function ‘int main()’:
ref3.cpp:15:16: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
   char *str1 = "kay";
                ^~~~~
ref3.cpp:16:16: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
   char *str2 = "dot";
*/