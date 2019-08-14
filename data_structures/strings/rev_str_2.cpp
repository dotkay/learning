// rev_str_2.cpp
// taking care of ignoring leading and trailing spaces
// in the input string

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
  while(lo < hi)
    swap(lo++, hi--);
}

std::string rev_str(std::string s)
{
  char* lo = NULL;
  char* hi = &s[0];

  while(*hi)
  {
    // adjust lo pointer in case of leading
    // spaces in the string
    if ((lo == NULL) && (*hi != ' ')) 
      lo = hi; 
    if (lo && ((*(hi+1) == ' ' ) || (*(hi+1) == '\0')))
    {
      reverse(lo, hi);
      lo = NULL;
    }
    hi++;
  }
  // now each word in the string is reversed; reverse
  // the whole string in order to correct that
  reverse(&s[0], hi-1);
  return s;
}

int main()
{
  std::string s = "hello sir  ";
  //char* c = &s[0];
  //reverse(&c[0], &c[4]);
  //std::cout << c << std::endl;
  std::string res;
  res = rev_str(s);
  std::cout << res << std::endl;

  return 0;
}
