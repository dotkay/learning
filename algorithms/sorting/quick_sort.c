#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// function that partitions an array given a
// start and an end index around a pivot
// the element at end index is chosen to be
// the pivot
int quick_partition(int A[], int start, int end) {
    // choose a pivot element
    // we will choose the last element in the list
    // as the pivot, so pivot = A[end]
    int pivot = A[end];
    // start with the beginning of the list
    // to partition the list - to track the partition
    // we introduce part_index to be the start
    int part_index = start;
    // traverse the loop and keep pushing (using swap)
    // elements less than pivot to the left of the list
    int i;
    for (i = start; i < end; i++) {
        if (A[i] <= pivot) {
            swap(&A[i], &A[part_index]);
            part_index++;
        }
    }
    // now pivot itself is at the end and the list
    // to the left of the pivot is partitioned into two
    // towards the left are the elements less than pivot
    // and towards the right are the elements greater than
    // pivot
    // we just have to move the pivot to the current
    // part_index so that the pivot element is at the
    // center of the partition
    swap(&A[part_index], &A[end]);
    return part_index;
}

// if the input array is already sorted and if we choose
// the last element of the pivot (worst case scenario), we
// will incur O(n^2) running time, as we will go through
// the partitioning n-1 times instead of log n times
// in order to avoid this, we make choosing the pivot a
// random function and use the rest of the partitioning
// function as above
int randomized_partition(int A[], int start, int end) {
    // initialize random seed
    srand(time(NULL));
    // random number between start and end
    int pivot = rand() % end + start;
    swap(&A[end], &A[pivot]);
    quick_partition(A, start, end);
}

// this recursive function uses the above partition function
// and partitions the array around the pivot repeatedly
void quick_sort_r(int A[], int start, int end) {
    // base condition 
    if (start >= end)
        return;
    // recursion
    // partition the input array A[]
    
    int part_index = quick_partition(A, start, end);
    /* int part_index = randomized_partition(A, start, end); */
    
    // recursively call quick_sort_r on the two
    // partitions created by the start and end
    quick_sort_r(A, start, part_index-1);
    quick_sort_r(A, part_index+1, end);
}

// quick_sort function that calls the above function
// I introduced this just for uniformity - all the other
// sorting implementations take an array A and the size n
// and I wanted this also to have the same input signature
void quick_sort(int A[], int n) {
    int start = 0;
    int end = n-1;
    quick_sort_r(A, start, end);
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
    quick_sort(A, n);
    printf("\nArray after sorting:");
    print_arr(A, n);
    return 0;
}