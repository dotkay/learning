// Queue Implementation
// (using Array)

#include <iostream>

using namespace std;

#define MAXSIZE 100

class Queue {
  private:
    int front, rear;
    int arr[MAXSIZE];
  public:
    Queue ();
    void enqueue (int item);
    int dequeue ();
    void print_queue ();
    bool is_empty ();
};

Queue::Queue () {
  front = 0;
  rear = -1;
}

void Queue::enqueue (int item) {
  if (rear >= MAXSIZE - 1)
    throw out_of_range("Queue is full. Nothing can be enqueued now.");
  
  else {
    arr[++rear] = item;
  }
}

int Queue::dequeue () {
  if (rear == -1)
    throw out_of_range("Can not dequeue from empty queue");
  
  return arr[front++];
}

bool Queue::is_empty () {
  return (front > rear);
}

void Queue::print_queue () {
  cout << "<-- ";
  for (int i=front; i<=rear; i++)
    cout << arr[i] << " ";
  cout << "<--\n";
}

int main () {

  Queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  q.print_queue();

  cout << "Dequeue ... " << q.dequeue() << endl;
  q.print_queue();

  cout << "Dequeue ... " << q.dequeue() << endl;
  q.print_queue();

  cout << "Dequeue ... " << q.dequeue() << endl;
  q.print_queue();

  if (q.is_empty())
    cout << "Queue is empty now!" << endl;

  return 0;
}