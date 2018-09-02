// All premutations of a string
// permutations1.cpp

#include <iostream>
#include <cstring>

using namespace std;

void swap (char &x, char &y) {
  char tmp;
  tmp = x;
  x = y;
  y = tmp;
  return;
}

// recursive function to swap two characters in 
// the string and generate a new permutation
// s     : string
// start : starting index
// end   : ending index
void permute(string s, int start, int end) {
  int i;
  if (start == end)
    cout << s << endl;
  else {
    for (i=start; i<=end; i++) {
      cout << "swapping " << s[start] << " with " << s[i] << endl;
      swap(s[start], s[i]);
      permute(s, start+1, end);
      //cout << "2. swapping " << s[start] << " with " << s[i] << endl;
      swap(s[start], s[i]);
    }
  }
}


int main () {
  string str;
  cout << "enter an input string: ";
  cin >> str;
  int n = str.length();
  permute(str, 0, n-1);

  return 0;
}