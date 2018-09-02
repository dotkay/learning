// understanding references
// ref2.cpp

#include <iostream>
using namespace std;

int fun (int &x) {
  return x;
}

int main () {
  cout << fun(10);
  return 0;
}

/*
ref2.cpp: In function ‘int main()’:
ref2.cpp:12:17: error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
   cout << fun(10);
                 ^
ref2.cpp:7:5: note:   initializing argument 1 of ‘int fun(int&)’
 int fun (int &x) {
     ^~~
*/