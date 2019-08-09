// Given a number n and an integer k, determine if kth bit is set 
// in binary representation of n

#include <iostream>

int main()
{
  int N; // no. of test cases
  std::cin >> N;
  while (N--)
  {
    int n, k; // input number, k
    std::cin >> n;
    std::cin >> k;
    int res;
    res = n & (1 << (k-1));
    if (res != 0)
      std::cout << "bit at position " << k << " is set in " << n << std::endl;
    else
      std::cout << "bit at position " << k << " is not set in " << n << std::endl;
  }
  return 0;
}
