// Array rotation
// Instead of O(n*d) naive algorithm as in
// array_rotation_simple.cpp, here we try to
// do it in O(n) (and auxiliary space O(d))

#include <iostream>
using namespace std;


void print_arr (int arr[], int n) {
  cout << "[ ";
  for (int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
  cout << "]\n";
}

void rotate_arr_by_d (int arr[], int n, int d) {
  int* tmp = new int[d];
  // copy the d elements from the array 
  for (int i=0; i<d; i++)
    tmp[i] = arr[i];
  // shift the rest of the array
  for (int i=0; i<n-d; i++)
    arr[i] = arr[d+i]; 
  // copy over elements from tmp
  for (int i=0; i<d; i++)
    arr[n-d+i] = tmp[i];
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