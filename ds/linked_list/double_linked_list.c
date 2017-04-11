// double_linked_list.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create_node(int item) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(struct Node** head, int item) {
    struct Node* new_node = create_node(item);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    (*head)->prev = new_node;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct Node* list) {
    struct Node* tmp = list;
    while (tmp != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void print_list_reverse(struct Node* list) {
    struct Node* tmp = list;
    printf("NULL");
    if (tmp == NULL) {
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    while (tmp != NULL) {
        printf(" <- %d", tmp->data);
        tmp = tmp->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int i, n, x;
    printf("How many items do you want to insert?\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the number\n");
        scanf("%d", &x);
        insert_at_head(&head, x);
    }
    print_list(head);
    print_list_reverse(head);
    return 0;
}