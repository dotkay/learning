// pow2.cpp
// Improvement of pow.cpp
// (storing intermediate values instead of recomputing)

#include <iostream>

using namespace std;

int power_x_y (int x, int y) {
  int tmp;
  if (y == 0)
    return 1;
  tmp = power_x_y(x, y/2);
  if (y % 2 == 0) 
    return tmp * tmp;
  else
    return x * tmp * tmp;
}

int main () {
  int x, y;
  cout << "Enter x and y to compute x^y: " << endl;
  cin >> x >> y;
  cout << "x ^ y is: " << power_x_y (x, y) << endl;
  return 0;
}