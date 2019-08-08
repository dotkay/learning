// How to figure out if the given input number is a power of two

#include <iostream>

int main()
{
  bool res;   // to store the result
  int N;     // no. of test cases
  std::cin >> N;

  while (N--)
    {
      int n; // input number
      std::cin >> n;
      res = false;
      // numbers that are powers of two
      // have this property that all bits
      // except one will be 0s. For eg.
      // 8 is 2^3, 1000 here, all the bits
      // in positions 1, 2, 3 are 0 and only
      // one bit is set (at position 4)

      // since we like & operator very much
      // now we need to find a number such that
      // once you & n with, powers of two ns will
      // have a unique result

      int pow_test = n & (n-1);
      
      // since (n-1) will have 1 at all bit positions
      // except the power of two position, this is a 
      // great candidate

      if (pow_test == 0)
        res = true;
    }
  
  if (res)
    std:: cout << "yes, given input is a power of two" << std::endl;
  else
    std::cout << "no, given input is not a power of two" << std::endl;

  return 0;
}
