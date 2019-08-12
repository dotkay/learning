// rem_duplicates.cpp

#include <iostream>

void print_arr (int arr[], int n)
{
  std::cout << "[ ";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";
  std::cout << "]" << std::endl;
}

void swap(int* x, int* y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

int rem_dups(int arr[], int n)
{
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != arr[i+1])
      swap(&arr[j++], &arr[i]);
  }
  print_arr(arr, n);
  return j;
}

int main()
{
  int N; // no. of test cases
  std::cin >> N;
  while (N--)
  {
    int n; // size of array
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
      std::cin >> arr[i];
    
    int res;
    std::cout << rem_dups(arr, n);
  }
  return 0;
}