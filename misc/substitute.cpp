#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Substitute {
	public:
    	int getValue(string, string);
};

int Substitute::getValue(string key, string code) {
	int k, c;
    vector<int> res;
    k = key.length();
    c = code.length();
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < k-1; j++) {
            if (code[i] == key[j])
                res.push_back(j+1);
        }
        if (code[i] == key[9])
            res.push_back(0);
    }
    int result = 0;
    for (int a = 0; a < res.size(); a++) {
    	result = result * 10 + res.at(a);
    }
    return result;
}

int main () {
  Substitute s;
  string key, code;
  int res;
  cout << "Enter the key string: \n";
  cin >> key;
  cout << "Enter the code string: \n";
  cin >> code;
  res = s.getValue(key, code);
  cout << res;
  return 0;
}