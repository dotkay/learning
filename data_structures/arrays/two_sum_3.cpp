// two_sum_3.cpp
// two sum problem for sorted arrays
// uses binary search as the array is sorted

#include <iostream>

std::pair<int, int> two_sum(int arr[], int n, int t)
{
  int lo, hi;
  std::pair<int, int> res (-1, -1);
  
  for (int i = 0; i < n; i++)
  {
    lo = i+1;
    hi = n - 1;
    int tmp = t - arr[i];
    while (lo <= hi)
    {
      int mid = (lo + (hi - lo)/2);
      if (arr[mid] == tmp)
      {
        res.first = arr[i];
        res.second = arr[mid];
        return res;
      }
      else if (arr[mid] > tmp)
        hi = mid - 1;
      else 
        lo = mid + 1;
    }
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