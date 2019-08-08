#include <iostream>
#include <cmath>

int main()
{
  
  int N;
  int res;       // to store the result
  std::cin >> N; // no. of test cases
  while (N--)
    {
      int n;     // input number
      std::cin >> n;
      
      // we take the two's complement of n
      // the idea is to generate a number
      // whose all bits are flipped except
      // the MSB
      int two_comp = -n;
      
      // now & with the original number, this
      // would make all except the right most 
      // set bit 0
      int one_bit_set_number = n & -n;
      
      // since bit positions correspond to log
      // powers of two, find out the int. position
      int bit_pos = log2(one_bit_set_number);
      
      // if we count the right-most bit as 1 (as we should)
      // unlike array's 0-indexing, we need to add 1
      res = bit_pos + 1;
    }

  std::cout << "right most set bit position: " << res << std::endl;
  
  return 0;
}
