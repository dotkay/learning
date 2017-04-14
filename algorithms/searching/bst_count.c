#include <stdio.h>
#include <stdlib.h>

/*
Problem: Given a sorted list with duplicates, find 
         the count (number of occurences) of a given
         element in the array
*/

void print_arr(int A[], int n) {
    int i;
    printf("\n[");
    for (i = 0; i < n; i++) {
        printf(" %d", A[i]);
    }
    printf(" ]\n");
}

// to find the first occurence of x
int bst_find_first(int A[], int n, int x) {
    int low, high, mid;
    // initialize result to -1 
    // if we end up not finding x we will still
    // return -1, the initial value of result
    int result = -1;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        // if the element is at the mid-point
        // store the index and continue searching
        // for other occurences in the left half
        // since we are interested in finding the first
        // occurence, we search the left half
        if (x == A[mid]) {
            result = mid;
            high = mid-1;
        }
        // search the left half
        else if (x < A[mid])
            high = mid-1;
        // search the right half
        else if (x > A[mid])
            low = mid+1;
    }
    return result;
}

// to find the last occurence of x
int bst_find_last(int A[], int n, int x) {
    int low, high, mid;
    // initialize result to -1 
    // if we end up not finding x we will still
    // return -1, the initial value of result
    int result = -1;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        // if the element is at the mid-point
        // store the index and continue searching
        // for other occurences in the right half
        // since we are interested in finding the last
        // occurence, we search the right half
        if (x == A[mid]) {
            result = mid;
            low = mid+1;
        }
        // search the left half
        else if (x < A[mid])
            high = mid-1;
        // search the right half
        else if (x > A[mid])
            low = mid+1;
    }
    return result;
}

// linear scan of the array to count the occurences
// takes O(n) time in worst case
int linear_find_count(int A[], int n, int x) {
    int count = 0;
    int i;
    for (i = 0 ; i < n; i++) {
        if (A[i] == x)
            count++;
        // since the input list is sorted
        // we can break out of the loop once
        // we encounter a number > x
        else if (A[i] > x)
            break;
    }
    return count;
}

// reuse our bst_find_first and bst_find_last
// that take O(log n) time. This works as the 
// list is sorted the duplicates stay together
// in the list
int log_find_count(int A[], int n, int x) {
    int count = 0;
    int first = bst_find_first(A, n, x);
    int last = bst_find_last(A, n, x);
    if (first != -1 && last != -1)
        count = last - first + 1;
    return count;
}

int main() {
    int arr[12] = { 1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11};
    int linear_find_5 = linear_find_count(arr, 12, 5);
    printf ("5 occurs %d time(s) in the array\n", linear_find_5);
    int log_find_9 = log_find_count(arr, 12, 9);
    printf ("9 occurs %d time(s) in the array\n", log_find_9);
    return 0;
}