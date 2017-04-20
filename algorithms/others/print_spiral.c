#include <stdio.h>
/*
    Problem: Given a 2D array, print the elements in a spiral
             order - clockwise from top to bottom. 
             For example, for the following input 2D array,

             T -> a1 a2 a3 a4
                  b1 b2 b3 b4
                  c1 c2 c3 c4
             B -> d1 d2 d3 d4
                  ^         ^
                  L         R  

             we would print:
             a1 a2 a3 a4 b4 c4 d4 d3 d2 d1 c1 b1 b2 b3 c3 c2 

            in order to keep track of which row/col we are 
            printing we mark T (Top row), B(Bottom row), 
            L(Left column) and R (Right column) and manage
            the direction using a variable dir: {0, 1, 2, 3}
            0 - left-to-right
            1 - top-to-bottom
            2 - right-to-left
            3 - bottom-to-top
*/

void print_2d_arr(int nrow, int ncol, int arr[nrow][ncol]) {
    for (int i = 0; i < nrow; i++) {
        printf("[");
        for (int j = 0; j < ncol; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf ("]\n");
    }
}

void print_spiral(int nrow, int ncol, int arr[nrow][ncol]) {
    int top, bottom, left, right;
    // start direction (left-to-right)
    int dir = 0;
    // initial boundary to be printed (ref to img above)
    top = 0;            // top-most row to be printed
    bottom = nrow - 1;  // bottom-most row to be printed
    left = 0;           // left-most col to be printed
    right = ncol - 1;   // right-most col to be printed
    printf ("[ ");
    while (left <= right && top <= bottom) {
        // what to do in the four directions
        // left-to-right printing
        if (dir == 0) {
            // print the top row
            for (int i = left; i <= right; i++) 
                printf("%d ", arr[top][i]);
            top++;   // move top-most row to be printed
            dir = 1; // set the next direction
        }
        if (dir == 1) {
            // print the right column
            for (int j = top; j <= bottom; j++)
                printf("%d ", arr[j][right]);
            right--; // move right-most col to be printed
            dir = 2;
        }
        if (dir == 2) {
            // print the bottom row
            for (int i = right; i >= left; i--)
                printf("%d ", arr[bottom][i]);
            bottom--; // move bottom-most row to be printed
            dir = 3; 
        }
        if (dir == 3) {
            // print the left col
            for (int j = bottom; j >= top; j--)
                printf("%d ", arr[j][left]);
            left++; // move left-most row to be printed
            dir = 0;
        }
    }
    printf("]\n");
}

int main() {
    int A[4][4] = { {2, 4, 6, 8}, {5, 9, 12, 16}, {2, 11, 5, 9}, {3, 2, 1, 8}};
    print_2d_arr(4, 4, A);
    printf("Printing the array in spiral form...\n");
    print_spiral(4, 4, A);
    return 0;
}