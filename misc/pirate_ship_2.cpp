/**
You're the captain of a pirate ship and would like to 
calculate the state of the ship. There are two parameters 
- gold and pirates.

If there's less gold than pirates, that's always bad. If 
there's at least as much gold as pirates, that's good 
(even though the gold cannot be divided equally). If the 
gold can be divided by the pirates equally, that's great. 
However, if gold + pirates > 100, that's always bad since 
the ship may sink. Return an int corresponding to the 
state of the ship, according to the following:

0 - Bad
1 - Good
2 - Great

**/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Main {
public:
    int doStuff(int, int);
};

int Main::doStuff(int gold, int pirates) {
    if ((gold < pirates) || (gold + pirates > 100))
        return 0;          // 0 - Bad
    if ((gold > pirates) && (gold % pirates != 0))
        return 1;          // 1 - Good
    if ((gold >= pirates) && (gold % pirates == 0))
        return 2;          // 2 - Great
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