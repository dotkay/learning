// two_sum_2.cpp
// using hashmap

#include <iostream>
#include <unordered_map>

std::pair<int, int> two_sum(int arr[], int n, int target)
{
  std::pair<int, int> res (-1, -1);
  std::unordered_map<int, int> umap;
  std::unordered_map<int, int>::iterator it;
  for (int i = 0; i < n; i++)
  {
    it = umap.find(target - arr[i]);
    if (it == umap.end())
      umap.insert(std::make_pair(arr[i], target - arr[i]));
    else
    {
      res.first = it->first;
      res.second = it->second;
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
