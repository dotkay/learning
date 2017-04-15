#include <stdio.h>
#include <stdlib.h>

/*
    Problem: Given a circularly sorted list, and an
    element, find if the element exists in the list 
    and return it's index if it exists
*/

void print_arr(int A[], int n) {
    int i;
    printf("\n[");
    for (i = 0; i < n; i++) {
        printf(" %d", A[i]);
    }
    printf(" ]\n");
}

int find_x(int A[], int n, int x) {
    int low, high;
    int mid;
    low = 0;
    high = n-1;
    mid = (high - low) / 2;
    while (low <= high) {
        // check if the middle element is x, and if so, 
        // just return it
        if (A[mid] == x) 
            return mid;
        /* now, the idea is to observe that there's a pivot
           point before and after which the elements are sorted
           the pivot point denotes the start of rotation. 
           now, compare the mid with the high, if A[mid] <= A[high]
           then mid-to-high fragment is sorted. If A[mid] <= x <= A[high]
           then we can just iteratively fragment this half (mid-to-high)
           looking for x 
           Key idea: look for x in the sorted fragment of the list
       */
        if (A[mid] <= A[high]) { // mid-to-high is sorted fragment
            if (x > A[mid] && x <= A[high])  // x lies in this fragment
                low = mid + 1; // search in the right fragment
            else 
                high = mid - 1;
        }
        else if (A[low] <= A[mid]) { // low-to-mid is sorted fragment
            if (x >= A[low] && x < A[mid]) // x lies in low-to-mid fragment
                high = mid - 1;
            else 
                low = mid + 1;
        }
    }
}

int main () {
    int n, i, x;
    int found = -1;
    printf ("Enter the number of elements you want in the array:\n");
    scanf ("%d", &n);
    int A[n];
    for (i = 0; i < n; i++) {
        printf ("Enter an array element:");
        scanf("%d", &A[i]);
    }
    print_arr(A, n);
    printf ("Enter the element to find:\n");
    scanf ("%d", &x);
    found = find_x(A, n, x);
    if (found != -1)
        printf ("Element %d found at index %d\n", x, found);
    return 0;
}