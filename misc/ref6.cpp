// understanding references
// ref6.cpp

#include <iostream>

using namespace std;

int &fun () {
  int x = 10;
  return x;
}

int main () {
  fun() = 30;
  cout << fun();
  return 0;
}

/*
ref6.cpp: In function ‘int& fun()’:
ref6.cpp:9:7: warning: reference to local variable ‘x’ returned [-Wreturn-local-addr]
   int x = 10;

run time - core dumped

Ref: ref1.cpp - it is very similar. 
The only difference being static int x instead
of int x here

While returning a reference we need to be careful that the object
being referred to does not go out of scope, as in the above case:
fun() returns a reference to an int (and it returns x - so reference
to x which is an int and which is also local). Once we get out of
fun() we lose the scope. Where as we can return a reference to a 
static variable (static int x as in ref1.cpp) as the object being
referred to (x) does not go out of scope (as it is static)
*/