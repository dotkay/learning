#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Main {
    public:
        bool is_prime(int);
        bool fast_is_prime(int);
};

bool Main::is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

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

int main () {
    int n;
    vector<int> res;
    cout << "Enter a number to be checked for primality: ";
    cin >> n;
    Main m;
    if (m.fast_is_prime(n))
        cout << "Yes, it is a prime!\n";
    else 
        cout << "No, it is not a prime!\n";
    return 0;
}