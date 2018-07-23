// Array rotation: Lets try to just juggle the elements
// of the input array, rearrange them in order to achieve
// our target rotation

// Idea: instead of moving one by one, divide the array
// into some segments and move the elements within the 
// segments
// How to divide into segments? This could be done in 
// several ways. Here, we are dividing it by the GCD of
// n (input array size) and d (rotation count)

#include <iostream>
using namespace std;

void print_arr (int arr[], int n) {
  cout << "[ ";
  for (int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
  cout << "]\n";
}

int gcd (int p, int q) {
  if (q == 0)
    return p;
  else
    return gcd (q, p%q);
}

void rotate_arr_gcd (int arr[], int n, int d) {
  int c = gcd(d, n);
  cout << "gcd(d, n) = " << c << endl;
  for (int i=0; i < c; i++) {
  
    // rotate the ith element in each block 
    // by using tmp variable
    int tmp = arr[i];
    int j = i;

    while (1) {
      // move to element in the next (+d) block
      int k = (j + d)%n; 
      
      if (k == i)
        break;
      
      printf("Swapping elements at (%d <- %d)\n", j, k);
      arr[j] = arr[k];
      j = k;
    } 
    arr[j] = tmp;
  }
  // complexity: O(n)
}

int main () {

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  int d = 3; // could be any constant 
             // amount to shift by

  cout << "Input array: \n";
  print_arr (arr, n);
  cout << "size of the array: " << n << endl;

  // left-rotate the array
  cout << "(Left) rotation by: " << d << endl;
  rotate_arr_gcd (arr, n, d);

  // array after rotation
  cout << "Array after rotation: \n";
  print_arr (arr, n);

  return 0;
}