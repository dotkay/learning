// findpair with sum in a sorted and rotated array

#include <iostream>

using namespace std;

void print_array (int arr[], int n) {
  cout << "[ ";
  for (int i=0; i<n; i++)
    cout << arr[i] << " ";
  cout << "]\n";
}

pair<int, int> findpair(int arr[], int arr_size, int sum) {
  pair<int, int> res = make_pair(-1,-1);
  int l, r;
  // first find the point around which
  // the sorted array is rotated
  int i;
  for (i=0; i < arr_size; i++) {
    if (arr[i+1] < arr[i])
      break;
  }
  // now we now the boundary of the sorted array
  l = (i+1)%arr_size;
  r = i;

  // traverse it looking for pairs with the sum
  while (l != r) {
    int lr_sum = arr[l] + arr[r];
    // check if the sum is l + r
    if (lr_sum == sum) {
      res.first = l;
      res.second = r;
      return res;
    }

    // if the current sum is less than sum
    // move to the higher sum (increasing l)
    if (lr_sum < sum) 
      l = (l + 1)%arr_size;
    else
      r = (arr_size + r - 1)%arr_size;
  }
  // return the default (-1,-1) if the search
  // is unsuccessful
  return res;
}

int main() {
  int A[] = {11, 15, 6, 8, 9, 10};
  int sum = 18;
  int n = sizeof(A)/sizeof(A[0]);

  pair <int, int> res;
  res = findpair(A, n, sum);
  print_array(A, n);
  cout << "Pair with sum " << sum << " :" << "(" << res.first << "," << res.second << ")\n";
  return 0;
}