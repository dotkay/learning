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

// selection sort function
void selection_sort(int A[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // start with the first element as 
        // min element
        int min = i;
        // select the min element traversing the
        // list and push it to the current min
        // curr min is the first element to
        // start with
        for (j = i+1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }
        // push the min element towards the head 
        // of the list
        swap(&A[i], &A[min]);
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
    //int A[] = {1, 7, 9, 3, 5, 11};
    //int n = 6;
    printf("Array before sorting:");
    print_arr(A, n);
    selection_sort(A, n);
    printf("\nArray after sorting:");
    print_arr(A, n);
    return 0;
}