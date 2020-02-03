// Euclid's algorithm for finding the 
// greatest common divisor
/*
Given two positive integers x, y how to find
the greatest integer that divides them both?
One straight-forward approach is to find the 
factors of x, y and multiply all the common
factors. But there's no efficient algorithm 
for factorization.

Essentially, gcd(x, y) = gcd (x mod y, y)
which is the same as gcd(x, y) = gcd (x - y, y)
as we can get x mod y by repeated subtractions

Assume x > y.
Two key ideas:
1. Any integer that divides both x and y must
   also divide x - y
   gcd (x, y) <= gcd(x - y, y)
2. Any integer that divides x - y and y must 
   also divide x and y
   gcd (x, y) >= gcd(x - y, y)

Every two consecutive recursive calls reduces
x by at least half (so it reduces the number of
bits required to represent by at least 1). So, 
in 2n recursive calls, the base case would be 
reached
*/


#include <iostream>
#include <cmath>

using namespace std;

int euclid_gcd (int x, int y) {
  // base case
  if (y == 0)
    return x;
  else
    return euclid_gcd(y, x % y);
}

int main () {
  int x, y;
  cout << "Enter two positive integers x, y: \n";
  cin >> x >> y;
  cout << "GCD of x and y = " << euclid_gcd(x, y) << endl;
  return 0;
}