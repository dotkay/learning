// fibonacci_it.cpp

#include <iostream>

int fibo(int n)
{
  int res;
  if (n < 2)
    res = n;
  else {
    int pre = 1;
    int curr = 2;
    int prepre = 0;
    for (int i = 2; i <= n; i++)
    {
      curr = prepre + pre;
      prepre = pre;
      pre = curr;
    }
    res = curr;
  }
  return res;
}

int main ()
{
  int N;
  std::cin >> N;
  while (N--)
  {
    int n;
    std::cin >> n;
    std::cout << "fib(" << n << "): " << fibo(n) << std::endl;
  }
  return 0;
}
