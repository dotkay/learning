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

void merge(int left[], int nL, int right[], int nR, int A[], int n) {
    int i, j, k = 0;
    while (i < nL && j < nR) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        }
        else {
            A[k] = right[j];
            j++;
        }
        k++;
    }
    // when one of the sub-arrays is exhausted
    // i.e. all the elements of the subarray have
    // been moved to the result, we just need to
    // copy the other subarray (which is already
    // sorted) to the result array
    while (i < nL) {
        A[k] = left[i];
        i++;
        k++;
    }
    while (j < nR) {
        A[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int A[], int n) {
    int i, mid;
    if (n < 2)
        return;
    mid = n/2;
    int left[mid];
    int right[n-mid];
    for (i = 0; i < mid; i++)
        left[i] = A[i];
    for (i = mid; i < n; i++)
        right[i-mid] = A[i];
    merge_sort(left, mid);
    merge_sort(right, n-mid);
    merge(left, mid, right, n-mid, A, n);
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
    merge_sort(A, n);
    printf("\nArray after sorting:");
    print_arr(A, n);
    return 0;
}