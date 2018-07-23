// Array rotation:
// Given an array of size n and an integer d, rotate the array 
// by d

#include <iostream>

using namespace std;

void print_arr (int arr[], int n) {
  cout << "[ ";
  for (int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
  cout << "]\n";
}

void rotate_arr_by_one(int arr[], int n) {
  int tmp = arr[0];
  int i;
  // walk through the array, all the elements
  // but the last one and copy move them by
  // one to the left, using a tmp variable
  for (i=0; i<n-1; i++) {
    arr[i] = arr[i+1];
  }
  arr[i] = tmp;
  // Space complexity: O(1)
  // additional space for storing tmp
}

void rotate_arr_by_d (int arr[], int n, int d) {
  // Time Complexity: O(d)
  for (int i=0; i< d; i++)
    // Time Complexity: O(n)
    rotate_arr_by_one (arr, n);
  // Total time complexity: O(n*d)
}

int main () {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
  int d = 2; // could be any constant 
             // amount to shift by

  cout << "Input array: \n";
  print_arr (arr, n);
  cout << "size of the array: " << n << endl;

  // left-rotate the array
  cout << "(Left) rotation by: " << d << endl;
  rotate_arr_by_d (arr, n, d);

  // array after rotation
  cout << "Array after rotation: \n";
  print_arr (arr, n);

  return 0;
}