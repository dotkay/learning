// tokens.cpp

#include <iostream>
#include <cstring>
#include <string>

int main()
{
  // c++ string
  std::string s = "this-is-a-string-of-tokens";

  // convert into cstring O(n) space
  char* cstr = new char[s.length()+1];
  // std::strcpy(cstr, s.c_str());
  
  // or using the following std::string method
  // cstr = (char*)s.c_str();

  // or using memory allocation guarantees provided by
  // C++11 and above
  cstr = &s[0];

  char* tok = strtok(cstr, "-");
  // O(n) time
  while (tok != NULL)
  {
    std::cout << tok << std::endl;
    tok = strtok(NULL, "-");
  }
  return 0;
}