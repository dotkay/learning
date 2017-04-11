// Linked List implementation of Stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// NOTE: Unlike what we did for Arrays, we don't 
// have the Stack Linked List as a global variable 
// and so we are having to pass the stack to each 
// of the functions.

struct Stack {
    int data;
    struct Stack* next;
};

void push(struct Stack** top, int item) {
    struct Stack* tmp = (struct Stack*)malloc(sizeof(struct Stack));
    tmp->data = item;
    tmp->next = *top;
    *top = tmp;
}

void pop(struct Stack** top) {
    if (*top == NULL) 
        return;
    struct Stack* tmp = *top;
    *top = (*top)->next;
    free(tmp);
}

void print_stack(struct Stack* top) {
    struct Stack* tmp = top;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int top_of_stack(struct Stack* top) {
    return (top->data);
}

bool is_empty(struct Stack* top) {
    if (top == NULL) {
        return true;
    }
    else 
        return false;
}

int main() {
    struct Stack* S = NULL;
    push(&S, 1);
    push(&S, 3);
    push(&S, 19);
    print_stack(S);
    pop(&S);
    printf("top of stack: %d\n", top_of_stack(S));
    print_stack(S);
    printf("is S empty?: %d", is_empty(S));
    return 0;
}