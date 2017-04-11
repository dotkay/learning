#include <stdio.h>

void swap(int* p, int* q) {
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

void print_arr (int A[], int n) {
    int i;
    printf("\n[ ");
    for (i = 0; i < n; i++) {
        printf(" %d,", A[i]);
    }
    printf (" ]\n");
}

void insertion_sort(int A[], int n) {
    int i, val, hole;
    for (i = 1; i < n; i++) {
        val = A[i];
        hole = i;
        // shift all the elements greater than
        // the hole element, one place to the 
        // right
        while (hole > 0 && A[hole-1] > val) {
            A[hole] = A[hole-1];
            hole--; 
        }
        // put the value into the hole
        A[hole] = val;
    }
}

int main() {
    int n, i;
    printf ("Enter the number of elements you want in your array A: \n");
    scanf("%d", &n);
    int A[n];
    printf ("Enter the array elements one by one:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Array before sorting:");
    print_arr(A, n);
    insertion_sort(A, n);
    printf("\nArray after sorting:");
    print_arr(A, n);
    return 0;
}