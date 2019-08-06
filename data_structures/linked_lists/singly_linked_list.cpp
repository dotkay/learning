// linked_list.cpp

#include <iostream>

class Node 
{
  private:
    int data;
    Node* next;
    Node(int item);
  friend class List;
};

Node::Node(int item)
{
  this->data = item;
  this->next = NULL;
}

class List
{
  private:
    Node* head;
    int length;
  public:
    List();
    void insert_item(int item);
    void tail_insert(int item);
    int get_size();
    Node* get_head();
    int get_head_data();
    void print_list(Node* head);
    void print_list_r(Node* head);
    Node* reverse_list(Node* head);
    Node* reverse_list_r(Node* head);
};

List::List()
{
  this->head = NULL;
  this->length = 0;
}

// inserts item to the head of the list
void List::insert_item(int item)
{
  if (head == NULL)
    head = new Node(item);
  else 
  {
    Node* tmp = new Node(item);
    tmp->next = head;
    head = tmp;
    length++;
  }
}

// inserts item to the tail of the list
void List::tail_insert(int item)
{
  Node* tmp = head;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }  
  Node* new_node = new Node(item);
  tmp->next = new_node;
}

// get the length of the list
int List::get_size()
{
  return (this->length);
}

// fetch the head pointer
Node* List::get_head()
{
  return (this->head);
}

// fetch the data in the head
int List::get_head_data()
{
  Node* hd = get_head();
  return hd->data;
}

// reverse the list (iterative)
Node* List::reverse_list(Node* head)
{
  Node* rest;
  Node* prev = NULL;

  while (head != NULL)
  {
    rest = head->next;
    head->next = prev;
    prev = head;
    head = rest;
  }
  return prev;
}

// reverse the list (recursive)
Node* List::reverse_list_r(Node* head)
{
  // base case
  if (head == NULL || head->next == NULL)
    return head;
  // recursion
  Node* tmp = reverse_list_r(head->next);
  head->next->next = head; // reverse the pointers
  head->next = NULL;
  return tmp;
}


// prints the list
void List::print_list(Node* head)
{
  Node* tmp = head;
  while (tmp != NULL)
  {
    std::cout << tmp->data << " -> ";
    tmp = tmp->next;
  }
  std::cout << "NULL" << std::endl;
  this->head = head;
}

// prints the list (recursive)
void List::print_list_r(Node* head)
{
  Node* tmp = head;
  if (tmp == NULL)
  {
    std::cout << "NULL" << std::endl;
    return;
  }
  std::cout << tmp->data << " -> ";
  print_list_r(tmp->next);
  this->head = head;
}

int main()
{
  List* l = new List();
  l->insert_item(1);
  l->insert_item(2);
  l->insert_item(3);
  l->insert_item(4);
  l->print_list(l->get_head());

  std::cout << "reversing the list ... " << std::endl;
  l->print_list_r(l->reverse_list(l->get_head()));
  
  std::cout << "head data: " << l->get_head_data() << std::endl;

  std::cout << "reversing the list again ... " << std::endl;
  l->print_list(l->reverse_list_r(l->get_head()));

  return 0;
}