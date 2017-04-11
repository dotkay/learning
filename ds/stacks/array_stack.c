// Array implementation of Stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 101
int A[MAX_SIZE];       // stack with initial size
int top = -1;          // top of the stack                

void push(int item) {
    if (top == MAX_SIZE-1) {
        printf("Error: Stack overflow!");
    }
    A[++top] = item;
}

void pop() {
    if (top == -1) {
        printf("Error: No element to pop");
        return;
    }
    top--;
}

int top_of_stack() {
    return A[top];
}

bool is_empty() {
    return (top == -1);
}

void print_stack() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    push(2);
    print_stack();
    push(5);
    print_stack();
    push(10);
    print_stack();
    pop();
    print_stack();
    printf("stack empty?: %d", is_empty());
    return 0;
}