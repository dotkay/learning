// two_sum_4.cpp
// two sum problem using two pointers
// assumes that the given array is sorted
// in ascending order

#include <iostream>

std::pair<int, int> two_sum(int arr[], int n, int t)
{
  int lo = 0;
  int hi = n - 1;
  std::pair<int, int> res;
  while (lo < hi)
  {
    int s = arr[lo] + arr[hi];
    if (s == t)
    {
      res.first = arr[lo];
      res.second = arr[hi];
      return res;
    }
    // if sum is less than the target we move
    // lo ahead, as we know the next element would
    // be greater (ascending order sorted array)
    else if (s < t)
      lo++;
    else
      hi--;
  }
}

int main()
{
  int N; // no. of test cases
  std::cin >> N;
  while (N--)
  {
    int t; // target value
    std::cin >> t;
    int n; // size of input array
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
      std::cin >> arr[i];
    std::pair<int, int> res (-1, -1);
    res = two_sum(arr, n, t);
    std::cout << res.first << ", " << res.second << std::endl;
  }
  return 0;
}