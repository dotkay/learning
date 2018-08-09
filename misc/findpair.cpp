// findpair.cpp

#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> findpair(int arr[], int arr_size, int sum)
{
  int l, r;

  // using the C++ STL sort() utility
  sort(arr, arr + arr_size);

  pair <int, int> idx;
  // let's get to finding the pair with the 
  // given sum
  l = 0;             // first element of arr
  r = arr_size - 1;  // last element of arr
  while (l < r) {
    if (arr[l] + arr[r] == sum) {
      idx = make_pair(arr[l], arr[r]);
      return idx;
    }
    // we know l has the smallest element
    // so if a[l] + a[r] < sum
    // we try to see if a[l+1] with a[r] is sum
    if (arr[l] + arr[r] < sum)
      l++;
    else 
      r--;
  }
  // if we reached here, we could not find a 
  // pair that adds up to sum
  return (make_pair(-1, -1));
}

int main()
{
  int A[] = {1, 4, 45, 6, 10, -8};
  int sum = 16;
  int n = 6;

  pair <int, int> res;

  res = findpair(A, n, sum);
  cout << "Pair of elements adding to sum found: (" << res.first << ", " << res.second << ")\n";
  
  return 0;
}