#include <stdio.h>
#include <stdlib.h>

/*
Problem: Given a sorted or circularly sorted list, 
         find the index of the min. element of the 
         list efficiently.
         Assume that there are no duplicates in the
         list. 
*/

int rotation_count(int A[], int n) {
    /* the key idea is to note that the number
       of rotations is actually the number of 
       elements to the left of the min element
       for example,
       if A: [2 3 5 8 11 12] is rotated once,
             [12 2 3 5 8 11] and when rotated twice,
             [11 12 2 3 5 8]
       there are two elements before 2 when rotated
       twice (in other words, the min element got 
       moved by 'n' mod 'n' positions after 'n' 
       rotations)
    */
    int low = 0;
    int high = n-1;
    int mid = (high - low) / 2;
    int next, prev;
    /* we try to find the position of the pivot 
       element, call it pivot element and we do
       this by binary search
       Property: for the pivot element both left
       and right elements are greater than the 
       pivot element
       case 1: if low <= high, this segment is
               already sorted and A[low] is the
               min (in that segment)
       case 2: pivot element property
       case 3: A[mid] <= A[high], search the left 
               fragment
       case 4: A[mid] >= A[low], search the right
               fragment
    */
    while (low <= high) {
        if (A[low] <= A[high])
            return low;
        next = (mid + 1) % n;
        prev = (mid + n - 1) % n;
        if (A[mid] <= A[next] && A[mid] <= A[prev])
            return mid;
        else if (A[mid] <= A[high])
            high = mid - 1;
        else if (A[mid] >= A[low])
            low = mid + 1;
    }
}

void print_arr(int A[], int n) {
    int i;
    printf("\n[");
    for (i = 0; i < n; i++) {
        printf(" %d", A[i]);
    }
    printf(" ]\n");
}

int main() {
    int x, i;
    int r_count = 0;
    printf ("How many elements do you want in your array?:\n");
    scanf("%d", &x);
    int A[x];
    for (i = 0; i < x; i++) {
        printf ("enter the number:");
        scanf("%d", &A[i]);
    }
    printf ("this is your array\n");
    print_arr(A, x);
    r_count = rotation_count(A, x);
    printf ("The number of rotations of your sorted array is: %d\n", r_count);
    printf ("The index of min. element in the array is: %d\n", r_count);
    return 0;
}