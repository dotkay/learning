// Computing power
// (iterative)

#include <iostream>

using namespace std;

// Computing x ^ y
int power_x_y (int x, int y) {

  // check if y=0, 
  // in which case we just return 1
  if (y == 0)
    return 1;

  // check if y is even
  // in which case recursively call on y/2
  // x ^ y = (x ^ y/2) * (x ^ y/2)
  if (y % 2 == 0)
    return power_x_y(x, y/2) * power_x_y(x, y/2); 

  // incorporate the remaining 
  // 2 ^ 5 = (2^ 5/2) * (2^ 5/2) * 2
  // x ^ y = (x^ y/2) * (x^ y/2) * x
  else  
    return x * power_x_y(x, y/2) * power_x_y(x, y/2); 
}

int main () {
  int x, y;
  cout << "enter x and y to compute x ^ y: " << endl;
  cin >> x >> y;
  cout << "x ^ y is: " << power_x_y(x, y) << endl;

  return 0;
}