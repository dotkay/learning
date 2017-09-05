/**
You are working on an app to calculate tips. Given 2 
ints: a, for the purchase amount in cents, and b, for 
the quality of service received, can you calculate the 
tip in cents? Round the answer down to the nearest cent. 
Calculate the tip according to the following table:

Quality	Percent	decimal
1   	5%	    0.05
2	    10%	    0.1
3	    15%	    0.15
4	    20%	    0.2
5	    25%	    0.25

Example Input/Output
Given an input of 1000 3, return 150.
**/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Main {
public:
    int doStuff(int, int);
};

int Main::doStuff(int amount, int quality) {
    double tip;
    if (quality == 1) 
        tip = 0.05;
    else if (quality == 2)
        tip = 0.1;
    else if (quality == 3)
        tip = 0.15;
    else if (quality == 4)
        tip = 0.2;
    else if (quality == 5)
        tip = 0.25;
    return (int)(tip * amount);
}

int main () {
    int a, q;

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