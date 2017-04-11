// linked_list.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// inserts an item at the beginning of 
// the linked list
void insert_item(struct Node** head, int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = *head;
    *head = temp;
}

// inserts an item at a given position
void insert_item_at(struct Node** head, int item, int pos) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = NULL;
    if (pos == 1) {
        temp->next = *head;
        *head = temp;
    }
    struct Node* trav = *head;
    // since we want to insert at 'pos', we look
    // for 'pos-1'-th node in order to set the 
    // next pointer
    for (int i=0; i<pos-1; i++) {
        trav = trav->next;
    }
    temp->next = trav->next;
    trav->next = temp;
}

// deleting a node from the linked list
void delete_item_at(struct Node** head, int pos) {
    struct Node* trav = *head;
    // if the position is the head
    if (pos == 0) {
        *head = trav->next;
        free(trav);
        return;
    }
    // if the position is not the head
    int i;
    for (i=0; i<pos-1; i++) {
        trav = trav->next;
    }
    struct Node* tmp = trav->next;
    trav->next = tmp->next;
    free(tmp);
}

// reverse a linked list
struct Node* reverse_list(struct Node** head) {
    struct Node* curr;
    struct Node* prev;
    struct Node* next;
    curr = *head;          
    prev = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;        
    }
    *head = prev;
    return *head;
}

// reverse a linked list using recursion
// FIXME!
void reverse_list_r(struct Node* head) {
    if(head->next == NULL) {
        return;
    }
    // printf("[ %d ]", head->data);
    reverse_list_r(head->next);
    struct Node* tmp = head->next;
    tmp->next = head;
    printf("[ %d ]", (tmp->next)->data);
    head->next = NULL;
}

// print the linked list 
void print_list(struct Node* list) {
    while (list != NULL) {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// print a list using recursion
void print_list_r(struct Node* list) {
    if (list == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", list->data);
    print_list_r(list->next);
}

void reverse_print_r(struct Node* list) {
    if (list == NULL) {
        printf("NULL");
        return;
    }
    reverse_print_r(list->next);
    printf(" <- %d", list->data);
}

int main() {
    // pointer to the head node
    struct Node* head = NULL;     // empty list
    int n, i, x;
    printf("How many numbers do you want to insert?\n");
    scanf("%d", &n);
    // collect the numbers to be inserted one by one
    for (i = 0; i < n; i++) {
        printf("Enter the number \n");
        scanf("%d", &x);
        insert_item(&head, x);
        print_list(head);
    }
    // insert '4' at position 2
    printf("\ninserting 4 at position 2...\n");
    insert_item_at(&head, 4, 2);
    print_list(head);
    // delete item at position 2 (index 2 - so it will be the 3rd item)
    printf("\ndeleting item at position 2...\n");
    delete_item_at(&head, 2);
    print_list(head);
    // delete the item at the head (index 0)
    printf("\ndeleting item at the head (position 0)...\n");
    delete_item_at(&head, 0);
    print_list(head);
    // reversing the list
    // printf("\nreversing the list...\n");
    // head = reverse_list(&head);
    // print_list_r(head);   // uses recursive function
    // reverse_print_r(head);
    // reversing the list using recursive function
    printf("\n---------------------\n");
    print_list(head);
    printf("\nreversing the list using recursive function...\n");
    // head = reverse_list_r(&head);
    reverse_list_r(head);
    // print_list(head);

    return 0;
}