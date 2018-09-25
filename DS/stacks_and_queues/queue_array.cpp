// Queue implementation
// (using Array)

#include <iostream>

using namespace std;

#define MAXSIZE 100

class Queue {
  private:
    int *arr;          // array implementing the queue
    int front, rear; 
    int capacity;      // capacity of the queue
    int count;         // current number of elements in the queue

  public:
    // constructor
    Queue (int size);
    void enqueue (int item);
    int dequeue ();
    void print_queue ();
};

Queue::Queue (int size) {
  arr = new int[size];
  capacity = size;
  front = 0;
  rear = -1;
  count = 0;
}

void Queue::enqueue (int item) {
  if (capacity >= MAXSIZE-1)
    throw out_of_range("Queue is full. No place to enqueue.");
  else {
    arr[rear++] = item;
    count++;
  }
}

void Queue::print_queue () {
  cout << "--  ";
  for (int i=0; i<count; i++)
    cout << arr[i] << " ";
  cout << "  --\n";
}

int main () {
  Queue q(5);

  q.enqueue(10);
  q.enqueue(20);

  q.print_queue();

  return 0;
}