#include <iostream>

int main()
{
  int res;     // to store the result
  int N;       // no. of test cases

  std::cin >> N;
  while (N--)
    {
      int n;
      std::cin >> n;  // input number
      int cnt = 0;
      while (n != 0)
        {
          n = n >> 1;
          cnt++;
        }
      std::cout << "right-most set bit position: " << cnt << std::endl;
    }

  return 0;
}
