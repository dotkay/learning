/**
Given a number from 1 to 4 (inclusive), return a word representation of the number. For example, given 2, return two. If the number is greater than 4, return the phrase too large. If the number is less than 1, return the phrase too small.

The input starts with N, the number of cases.
N lines follow, which each contains 1 integer.
Print out the correct phrase for each case on its own line.
**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Main {
	public:
		string doStuff (int);
};

string Main::doStuff (int n) {
	string result = "";
	if (n < 1) {
		result = "too small\n";
		return result;		
	}
	else if (n > 4) {
		result = "too large\n";
		return result;
	}
    if (n == 1)
        result = "one\n";
    else if (n == 2)
        result = "two\n";
    else if (n == 3) 
        result = "three\n";
    else if (n == 4) 
        result = "four\n";
	return result;
}

int main() {
    int N, i;
    vector<int> invec;
	//cout << "Enter the number of cases: ";
	cin >> N;
	Main m;
	for (i = 0; i < N; i++) {
		int n;
		cin >> n;
		invec.push_back(n);
    }
    for (i = 0; i < invec.size(); i++) {
        cout << m.doStuff(invec.at(i));
    }
}