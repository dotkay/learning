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

// delete - delete a given node (key) from the list
void delete(struct node** head, int key)
{
	// find the node previous to the key
	struct node* prev = *head;
	
	// check if head node itself has the key
	if (prev->item == key) {
		*head = prev->next;
		free(head);
		return;
	}
	
	while ((prev->next) != NULL && (prev->next)->item != key) {
		prev = prev-> next;
	}
	struct node* temp = prev->next;
	// now prev is the node previous to the one to be deleted
	// change prev's next pointer to point to the next of the
	// one to be deleted
	
	if (temp == NULL) { // didn't find a node with the key
		printf("Key %d not found in the list...\n", key);
		return;
	}
	prev->next = (temp)->next;
	free(temp);
	return;	
}

// delete_at - delete a node at a given position (integer) in the list
void delete_at(struct node** head, int pos)
{
	int p = 0;
	
	if (pos == 0) {
		struct node* old_head = *head;
		*head = old_head->next;
		free(old_head);
		return;
	}
	// traverse the list to find the node in the 
	// previous position to the one to be deleted
	struct node* n = *head;
	while (n->next != NULL) {
		p++;
		n = n->next;
		if (p == pos) {
			delete(head, n->item);
			return;
		}
	}
	printf("Position %d not found in the list...\n", pos);
}

// printlist - to print the list
void printlist (struct node* p)
{
	while (p != NULL) {
		printf("%d --> ", p->item);
		p = p->next;
	}
	printf(" NULL\n\n");
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
	
	printf("Deleting 3 from the list...\n");
	
	delete(&head, 3);
	
	printlist(head);

	printf("Deleting 6 from the list...\n");
	
	delete(&head, 6);
	
	printlist(head);
	
	printf("Deleting at position 2...\n");
	
	delete_at(&head, 2);
	
	printlist(head);

	printf("Deleting at position 7...\n");
	
	delete_at(&head, 7);
	
	printlist(head);
	
	return 0;
}


	