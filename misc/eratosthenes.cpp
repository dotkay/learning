// eratosthenes.cpp
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Main {
    public:
        bool fast_is_prime(int);
        vector<int> eratosthenes(int);
};

bool Main::fast_is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int m = (int)sqrt((double)n);
    for (int i = 3; i <= m; i+=2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> Main::eratosthenes(int n) {
    vector<int> result;
    vector<bool> prime(n+1, true);
    prime[0] = false;
    prime[1] = false;
    int m = (int)sqrt((double)n);
    for (int i = 2; i <= m; i++) {
        if (fast_is_prime(i))
            result.push_back(i);
            for (int k = i*i; k <= n; k += i) {
                prime[k] = false;
            }
    }
    return result;
}

int main () {
    int N;
    Main m;
    vector<int> res;
    cout << "Enter a number: ";
    cin >> N;
    res = m.eratosthenes(N);
    for (int i = 0; i < res.size(); i++) {
        cout << res.at(i) << " ";
    }    
    return 0;
}