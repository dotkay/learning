// understanding references
// ref5.cpp

#include <iostream>

using namespace std;

int main () {
  int *ptr = NULL;
  int &ref = *ptr;
  cout << ref;

  return 0;
}

/*
It is possible to have references that don't refer to a 
valid location - NULL above. It will compile fine, but 
run time errors will occur (core dumped above case)
*/