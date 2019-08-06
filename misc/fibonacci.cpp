// fibonacci.cpp

#include <iostream>

int fibo(int n)
{
  int res;
  if (n < 2)
    res = n;
  else
    res = fibo(n - 1) + fibo (n - 2);
  return res;
}

int main()
{
  int N;
  std::cin >> N;
  while (N--)
  {
    int n;
    std::cin >> n;
    std::cout << "F(" << n << "): " << fibo(n);
  }
  return 0;
}