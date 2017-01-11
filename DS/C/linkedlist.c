// linkedlist.c

#include "stdio.h"
#include "malloc.h"
// node structure
struct node
{
	int item;           // data
	struct node* next;  // pointer to next node in the list
};

// API

// insert - insert a new node at the head of the list
void insert(struct node** head, int data)
{
	// declare a new node
	// allocate memory for it
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	// fill in the data
	new_node->item = data;
	// make the new node point to the rest of the list (pointed by old head)
	// since we are inserting this node at the head of the list
	new_node->next = *(head);
	// new_node is the new head now
	*head = new_node;
}

// insert_after - insert a new node after a given node
void insert_after(struct node* prev_node, int data)
{
	// declare a new node
	// allocate memory for it
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	// fill in the data
	new_node->item = data;
	// make the new_node's next point to prev_node's next
	new_node->next = prev_node->next;
	// make prev_node's next point to new_node
	prev_node->next = new_node;
}

// insert_last - insert a new node at the end of the list
void insert_last(struct node** head, int data)
{
	// declare a new node
	// allocate memory for it
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	// fill in the data
	new_node->item = data;
	// make the new node's next point to NULL 
	// this is going to be the last node anyway
	new_node->next = NULL;
	// traverse our list to find out the current last node
	struct node* p = *head;
	while (p->next != NULL) {
		p = p->next;
	}
	// now p has the last node in our original list
	p->next = new_node;
}

// printlist - to print the list
void printlist (struct node* p)
{
	while (p != NULL) {
		printf("%d --> ", p->item);
		p = p->next;
	}
	printf(" NULL\n");
}

// main
int main()
{
	// declare three nodes, initialize to NULL
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* fourth = NULL;
	
	// allocate space for them
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	fourth = (struct node*)malloc(sizeof(struct node));
	
	// fill in the data item for each node
	// link each node to the next
	head->item = 1;
	head->next = second;
	
	second->item = 2;
	second->next = fourth;
	
	fourth->item = 4;
	fourth->next = NULL;
	
	printlist(head);

	printf("Inserting 0 at the head....\n");
	
	insert(&head, 0);
	
	printlist(head);
	
	printf("Inserting 3 after second...\n");
	
	insert_after(second, 3);
	
	printlist(head);
	
	printf("Inserting 5 at the end...\n");
	
	insert_last(&head, 5);
	
	printlist(head);
	
	return 0;
}


	