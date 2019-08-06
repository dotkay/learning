// fibonacci_2.cpp
// using hashing to store intermediate results

#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> map;

int fibo(int n)
{
  int res;
  std::unordered_map<int, int>::iterator it = map.find(n);
  if (n < 2)
    res = n;
  else
  {
    if (it != map.end())
      res = map.at(n);
    res = fibo(n-1) + fibo(n-2);
  }
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
    std::cout << "fib(" << n << "): " << fibo(n) << std::endl;
  }
  return 0;
}