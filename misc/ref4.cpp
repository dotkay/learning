// understanding references
// ref4.cpp

#include <iostream>

using namespace std;

int main () {
  int x = 10;
  int *ptr = &x;
  int &*ptr1 = ptr;
  return 0;
}
/*
ref4.cpp: In function ‘int main()’:
ref4.cpp:11:9: error: cannot declare pointer to ‘int&’
   int &*ptr1 = ptr;
*/