// matching_paren.c 
// C program to match parenthesis in an expression using a stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 101

char A[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top == MAX_SIZE-1) {
        printf("Error: Stack overflow!");
        return;
    }
    A[++top] = item;
}

void pop() {
    if (top == -1) {
        printf("Error: Cannot pop from empty stack!");
        return;
    }
    top--;
}

char top_of_stack() {
    return A[top];
}

bool is_empty() {
    return (top == -1);
}

bool are_pair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}

bool is_balanced(char expr[]) {
    int n, i;
    n = strlen(expr);
    for (i = 0; i < n; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (is_empty() || !are_pair(top_of_stack(), expr[i])) {
                return false;
            }
            else
                pop();
        }
    }
    return is_empty();
}

int main() {
    char C[50];
    printf("Enter a string:\n");
    scanf("%s", &C);
    if (is_balanced(C))
        printf("Balanced!\n");
    else
        printf("Not Balanced!\n");
    return 0;
}