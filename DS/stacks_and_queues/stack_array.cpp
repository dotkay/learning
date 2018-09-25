// Stack implementation 
// (using Arrays)

#include <iostream>

using namespace std;

#define MAXSIZE 100
// Stack class
class Stack {
  int top;           // top of the stack
  int arr[MAXSIZE];  // array that implements the stack
  
  public:
    // constructor
    Stack ();
    
    // public methods
    bool push (int item);
    int pop ();
    int top_of_stack ();
    bool is_empty ();
    void print_stack ();
};

Stack::Stack () {
  top = -1;
}

bool Stack::push (int item) {
  // check if there's place to push
  if (top >= (MAXSIZE-1)) {
    cout << "Stack overflow!";
    return false;
  }

  // if there's place store the item
  else {
    arr[++top] = item;
    return true;
  }
}

int Stack::pop () {
  // check if there's anything to pop
  // or if the stack is empty
  if (top < 0) {
    throw out_of_range("Stack underflow!");
  }
  else {
    return arr[top--];
  }
}

int Stack::top_of_stack () {
  return arr[top];
}

bool Stack::is_empty () {
  return (top == -1);
}

void Stack::print_stack () {
  cout << "[ ";
  for (int i=0; i<=top; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

int main () {
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);

  s.print_stack();
  cout << "Top of stack: " << s.top_of_stack() << endl;

  cout << "popping: " << s.pop() << endl;
  s.print_stack();

  cout << "popping: " << s.pop() << endl;
  s.print_stack();

  return 0;
}