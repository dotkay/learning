// All permutations of a string (with handling duplicates)
// permutations2.cpp

#include <iostream>
#include <cstring>
#define DEBUG 1
using namespace std;

void swap (char *x, char *y) {
  char tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
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
      // handle duplicates
      if (DEBUG) {
      cout << "---------------------------------------------------------------------------------------\n";
      cout << "start: " << start << " i: " << i << "\t s.substr(start, end) " << s.substr(start, end-start+1) << "\t s.substr(i,end) " << s.substr(i,end-i+1) << endl;
      cout << "start: " << start << " i: " << i << "\t s.at(start): " << s.at(start) << "\t s.at(i): " << s.at(i) << endl;
      }
      if ( ((s.substr(start, end-start+1) == s.substr(start, end-i+1)) && (s.at(start) == s.at(i))) || (s.at(start) != s.at(i)) ) {
        cout << "swapping " << s[start] << " with " << s[i] << endl;
        swap(s[start], s[i]);
        permute(s, start+1, end);
        swap(s[start], s[i]);
      }
    }
  }
}

void permute2 (char* s, int start, int end) {
  int i;
  if (start == end)
    cout << s << endl;
  else {
    for (int i=start; i<=end; i++) {
      // handle duplicates
      cout << "--------------------------------------------------------------------\n";
      cout << "start: " << start << " i: " << i << "\t (s+start): " << (s+start) << "\t(s+i): " << (s+i) << endl;
      cout << "start: " << start << " i: " << i << "\t *(s+start): " << *(s+start) << "\t*(s+i): " << *(s+i) << endl;
      if ( ( (*(s+start) == *(s+i)) && (s+start == s+i) ) || (*(s+start) != *(s+i))  ) {
        cout << "\tswapping " << s[start] << " with " << s[i] << "  (start: " << start << ", i: "  << i << ")" << endl;
        swap((s+start), (s+i));
        permute2(s, start+1, end);
        swap((s+start), (s+i));
      }
    }
  }
}

int main () {
  string str = "AAB";
  int n = str.length();
  permute(str, 0, n-1);

  char s[] = "AAB";
  //permute2(s, 0, 2);
  return 0;
}
