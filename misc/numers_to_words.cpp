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