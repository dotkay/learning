// two_sum.cpp

#include <iostream>

// O(n^2) time, O(1) space
std::pair<int, int> two_sum(int arr[], int n, int target)
{
  std::pair<int, int> res (-1, -1);
  for (int i = 0; i < n; i++)
  {
    for (int j = i+1; j < n; j++)
      if (arr[i] == target - arr[j])
      {
        res.first = arr[i];
        res.second = arr[j];
      }
  }
  return res;
}

int main()
{
  int N; // no. of test cases
  std::cin >> N;
  while (N--)
  {
    int n; // size of input array
    std::cin >> n;
    int t; // target 
    std::cin >> t;
    std::pair<int, int> res;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
      std::cin >> arr[i];
    res = two_sum(arr, n, t);
    std::cout << res.first << ", " << res.second << std::endl;
  }
  return 0;
}
