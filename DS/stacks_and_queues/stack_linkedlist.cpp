// Stack implementation
// (using Linked List)

#include <iostream>

using namespace std;

// Node class for linked list's node
class Node {
  private:
    int data;
    Node *next;
    friend class Stack;
};

class Stack {
  private:
    Node *top;
  public:
    Stack ();
    void push (int item);
    void print_stack ();
    int top_of_stack ();
    bool is_empty ();
    int pop();
};

Stack::Stack () {
  top = NULL;
}

void Stack::push (int item) {
  // linked list implementation
  // so one can always add another node
  Node *tmp = new Node;
  tmp->data = item;
  tmp->next = top;

  top = tmp;
}

int Stack::top_of_stack () {
  return (top->data);
}

int Stack::pop () {
  if (top == NULL)
    throw out_of_range("Stack empty!");
  else {
    int res = top->data;
    Node *tmp = top->next;
    delete(top);
    top = tmp;
    return res;
  }    
}

bool Stack::is_empty () {
  return (top == NULL);
}

void Stack::print_stack () {
  Node *tmp = top;
  while (tmp != NULL) {
    cout << tmp->data << " ";
    tmp = tmp->next;
  }
  cout << "]\n";
}

int main () {
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.print_stack();
  cout << "Top of stack: " << s.top_of_stack() << endl;

  cout << "Popping stack: " << s.pop() << endl;
  s.print_stack();

  cout << "Popping stack: " << s.pop() << endl;
  s.print_stack();

  cout << "Popping stack: " << s.pop() << endl;

  if (s.is_empty())
    cout << "Stack is empty now!" << endl;

  return 0;
}