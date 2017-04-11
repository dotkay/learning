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

// bubble sort function
void bubble_sort(int A[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        int flag = 0;
        // n-i elements are already sorted
        // the biggest elements bubble towards higher indices
        // in every iteration
        for (j = 0; j < n-i-1; j++) {
            if (A[j] > A[j+1]) {
                swap(&A[j], &A[j+1]);
                // flag is set if a sorting happened during an
                // outer loop iteration
                flag = 1;
            }
        }
        // suppose we go through the outer j loop without
        // a single swap, it means that the list is already 
        // sorted. this is indicated by the flag being unset
        if (flag == 0) 
            return;
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
    bubble_sort(A, n);
    printf("\nArray after sorting:");
    print_arr(A, n);
    return 0;
}