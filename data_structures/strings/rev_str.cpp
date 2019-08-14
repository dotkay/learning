// rev_str.cpp

#include <iostream>
#include <string>

void swap(char* x, char* y)
{
  char tmp = *x;
  *x = *y;
  *y = tmp;
}

void reverse(char* lo, char* hi)
{
  while (lo < hi)
  {
    swap(lo++, hi--);
  }
}

std::string rev_str(std::string s)
{
  char* lo = &s[0];
  char* hi = &s[0];

  while (*hi)
  {
    hi++;
    // reached the end of the input string
    // reverse the whole thing
    if (*hi == '\0')
      reverse(lo, hi-1);
      
    // every time we encounter a delimiter
    // reverse the word before the delimiter
    else if (*hi == ' ')
    {
      reverse(lo, hi-1);
      lo = hi + 1;
    }
  }

  reverse(&s[0], hi-1);
  return s;
}

int main()
{
  std::string s = "  hello sir ";
  //char* c = &s[0];
  //reverse(&c[0], &c[4]);
  //std::cout << c << std::endl;
  std::string res;
  res = rev_str(s);
  std::cout << res << std::endl;

  return 0;
}