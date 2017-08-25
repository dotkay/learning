// maximum subset of an array

#include <iostream>
#include <vector>

using namespace std;

int max_subarray_sum_1 (vector<int> arr) {
    int res = 0;
    int n = arr.size();
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int c = a; c <= b; c++) {
                sum += arr[c];
                cout << "a %d b c sum" << a << b << c << sum << "\n";
            }
            res = max(res, sum);
        }
    }
    return res;
}

int max_subarray_sum_2 (vector<int> arr) {
    int res = 0;
    int n = arr.size();
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += arr[b];
            res = max(res, sum);
        }
    }
    return res;
}

// Kadene's algorithm
int max_subarray_sum_3 (vector<int> arr) {
    int res = 0, sum = 0;
    int n = arr.size();
    for (int a = 0; a < n; a++) {
        sum = max(arr[a], sum + arr[a]);
        res = max(res, sum);
    }
    return res;
}

int main () {
    vector<int> arr;
    int n;
    int res;
    std::cout << "enter the number of elements you want in the array: ";
    std::cin >> n;
    std::cout << "enter the elements: ";
    for (int i = 0; i < n; i++) {
        int in;
        std::cin >> in;
        arr.push_back(in);
    }
    res = max_subarray_sum_1(arr);
    std::cout << "maximum subarray sum: " << res << "\n";
    res = max_subarray_sum_2(arr);
    std::cout << "maximum subarray sum: " << res << "\n";
    res = max_subarray_sum_3(arr);
    std::cout << "maximum subarray sum: " << res << "\n";
    return 0;
}