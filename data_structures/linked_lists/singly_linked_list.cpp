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
    void print_list(Node* head);
    void print_list_r(Node* head);
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
  free(tmp);
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
}

int main()
{
  List* l = new List();
  l->insert_item(1);
  l->insert_item(2);
  l->insert_item(3);
  l->insert_item(4);
  l->print_list(l->get_head());
  l->tail_insert(5);
  l->print_list(l->get_head());
  l->print_list_r(l->get_head());
  return 0;
}