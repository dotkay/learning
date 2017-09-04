#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class Main {
public:
    string doStuff(int, int);
};

string Main::doStuff(int gold, int pirates) {

    if (gold + pirates > 100)
        return "false";
    if (gold >= pirates)
        return "true";
    else 
        return "false";
}

int main () {
    int N, i;
    // N: number of test cases
    // i: for indexing
    Main m;
    vector<std::pair<int, int> > invec;
    cin >> N;
    for (i = 0; i < N; i++) {
        int* list = new int[2];
        cin >> list[0] >> list[1];
        invec.push_back(std::make_pair(list[0], list[1]));
    }

    for (i = 0; i < invec.size(); i++) {
        cout << m.doStuff(invec.at(i).first, invec.at(i).second) << "\n";
    }

    return 0;
}