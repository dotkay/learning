// Computing power: x ^ y
// * handling negative y
// * handling floats

#include <iostream>

using namespace std;

float power_x_y (float x, int y) {
  float tmp;
  if (y == 0)
    return 1;
  tmp = power_x_y(x, y/2);
  if (y % 2 == 0)
    return tmp * tmp;
  else {
    // if y is positive the usual approach
    if (y > 0)
      return x * tmp * tmp;
    else
      return (tmp * tmp) / x;
  }
}

int main () {
  float x;
  int y;
  cout << "Enter x and y to compute x^y: " << endl;
  cin >> x >> y;
  cout << "x^y is: " << power_x_y(x, y) << endl;  

  return 0;
}