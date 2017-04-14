#include <stdio.h>
#include <stdlib.h>

void print_arr(int A[], int n) {
    int i;
    printf("\n[");
    for (i = 0; i < n; i++) {
        printf(" %d", A[i]);
    }
    printf(" ]\n");
}

int bst_find(int A[], int n, int x) {
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        // if the element is at the mid-point
        // return the index
        if (x == A[mid])
            return mid;
        // search the left half
        else if (x < A[mid])
            high = mid-1;
        // search the right half
        else if (x > A[mid])
            low = mid+1;
    }
    // if not found return -1
    return -1;
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

int main() {
    int arr[7] = {2, 4, 10, 10, 10, 18, 20};
    print_arr(arr, 7);

    // find if an element occurs in the array and 
    // if it's found return the index of occurence
    int found = bst_find(arr, 7, 10);
    int first_find = bst_find_first(arr, 7, 10);
    int last_find = bst_find_last(arr, 7, 10);
    if (found != -1)
        printf ("10 found at index %d\n", found);
    if (first_find != -1)
        printf ("10 is first found at index %d\n", first_find);
    if (last_find != -1)
        printf ("10 is last found at index %d\n", last_find);
    return 0;
}