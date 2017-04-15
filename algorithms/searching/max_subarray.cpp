#include <iostream>
#include <stdio.h>

using namespace std;

#define REP(i, a, n) for (int i = a; i <= n; i++)

void print_arr(int A[], int n) {
    int i;
    cout << "\n[ ";
    REP(i, 1, n) {
        cout << A[i-1] << " ";  // i-1 as index starts at 0
    }
    cout << "]\n";
}

/*
    Looping through the array and going through
    possible subarrays. Straight-forward but very
    inefficient - O(n^3) algorithm
*/
int max_subarray_On3(int A[], int n) { 
    int res = 0;            // result
    REP(i, 1, n) {
        REP(j, i, n) {      // different subarrays 
            int s = 0;      // subarray sum accumulator
            REP (k, i, j) { // sum diff subarrays
                s += A[k];
            }
            res = max(s, res);
        }
    }
    return res;
}

/*
    A simple optimization in the above algo to 
    make it slightly more efficient. we can
    compute the sum within the second inner loop
    itself - this removes one level of looping
    and it becomes an O(n^2) algorithm
*/
int max_subarray_On2(int A[], int n) {
    int res = 0;
    REP(i, 1, n) {
        int s = 0;
        REP (j, i, n) {
            s += A[j];
            res = max(res, s);
        }
    }
    return res;
}

/*
    Watch each subsegment as we traverse the 
    array and look for the max of
    1. current element
    2. accumulated sum upto that element
    O(n) algorithm - the best that could be done
*/

int max_subarray_On(int A[], int n) {
    int res = 0, s = 0;
    REP(i, 1, n) {
        s = max(A[i], s+A[i]);
        res = max(res, s);
    }
    return res;
}

int main() {
    int n, res;
    cout << "Enter the number of elements you want in the array\n";
    scanf ("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        cout << "enter an array element: ";
        scanf("%d", &A[i]);
    }
    print_arr(A, n);
    res = max_subarray_On3(A, n);
    cout << "max subarray sum (O(n^3)) is: " << res << "\n";
    res = max_subarray_On2(A, n);
    cout << "max subarray sum (O(n^2)) is: " << res << "\n";
    res = max_subarray_On(A, n);
    cout << "max subarray sum (O(n)) is: " << res << "\n";

    return 0;
}