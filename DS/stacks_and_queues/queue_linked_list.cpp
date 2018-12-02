// Queue Implementation
// (using Linked List)

#include <iostream>

using namespace std;

// Node class for linked list's node
class Node {
  private:
    int data;
    Node *next;
    friend class Queue;
};

class Queue {
  private:
    Node *front, *rear;
  public:
    Queue ();
    void enqueue (int item);
    void print_queue ();
    bool is_empty ();
    int dequeue ();
};

Queue::Queue () {
  this->front = NULL;
  this->rear = NULL;
}

void Queue::enqueue (int item) {
  // if the queue is empty
  // front and rear are the same, i.e the new item
  Node *new_item = new Node;
  new_item->data = item;
  new_item->next = NULL;

  if (rear == NULL) {
    front = rear = new_item;
    return;
  }

  // else add it to the rear end 
  // of the queue
  rear->next = new_item;
  rear = new_item;
}

int Queue::dequeue () {
  int res;
  // check if the queue is empty
  if (front == NULL)
    throw out_of_range("Empty queue");
  
  Node *dequeue_item = front;
  res = front->data;
  front = front->next;

  // now, if there was only one node
  // to pop front would point to NULL
  if (front == NULL)
    rear = NULL;

  delete (dequeue_item);
  return res;
}

bool Queue::is_empty () {
  return (front == NULL);
}

void Queue::print_queue () {
  Node *start = front;
  cout << "<-- ";
  while (start != NULL) {
    cout << start->data << " ";
    start = start->next;
  }
  cout << "<-- \n";
}

int main () {

  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  cout << "Printing the queue... ";
  q.print_queue();

  cout << "Dequeue..." << q.dequeue() << endl;
  q.print_queue();

  cout << "Dequeue..." << q.dequeue() << endl;
  q.print_queue();

  return 0;
}