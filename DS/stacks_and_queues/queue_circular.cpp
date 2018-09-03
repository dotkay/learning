// queue_circular.cpp

#include <iostream>
#include <vector>

using namespace std;

class CircQ {
  private:
    vector<int> data;
    int head;
    int tail;
    int size;
  public:
    CircQ (int size);
    bool enqueue (int item);
    bool dequeue ();
    bool is_empty ();
    bool is_full ();
    int front ();
    void print_q ();
    int get_size ();
    int find_head ();
    int find_tail ();
};

CircQ::CircQ (int n) {
  data.resize(n);
  head = -1;
  tail = -1;
  size = n;
}

bool CircQ::is_empty () {
  return (head == -1);
}

bool CircQ::is_full () {
  return (((tail + 1) % size) == head);
}

int CircQ::get_size () {
  return this->size;
}

int CircQ::find_head () {
  return head;
}

int CircQ::find_tail () {
  return tail;
}

bool CircQ::enqueue (int item) {
  if (is_full()) {
    return false;
  }
  if (is_empty()) {
    head = 0;
  }
  tail = (tail + 1) % size;
  data[tail] = item;
  return true;
}

bool CircQ::dequeue () {
  if (is_empty()) {
    return false;
  }
  if (tail == head) {
    tail = -1;
    head = -1;
    return true;
  }
  head = (head + 1) % size;
  return true;
}

int CircQ::front () {
  if (is_empty()) {
    return -1;
  }
  return data[head];
}

void CircQ::print_q () {
  if (is_empty())
    return;
  cout << "[ ";
  if (tail >= head) {
    for (int i=head; i <= tail; i++) 
      cout << data[i] << " ";
  }
  else {
    for (int i=head; i <= size; i++) 
      cout << data[i] << " ";
    for (int i=0; i <= tail; i++)
      cout << data[i] << " ";
  }
  cout << "]\n";
}

int main () {

  CircQ q(5);
  cout << "Q size: " << q.get_size() << endl;
  //q.enqueue(1);
  //q.enqueue(2);
  //q.enqueue(3);
  //q.enqueue(4);
  //q.print_q();
  //q.dequeue();
  //q.print_q();

  q.enqueue(5);
  q.enqueue(13);
  q.enqueue(8);
  q.enqueue(2);
  q.enqueue(10);
  cout << "head: " << q.find_head() << ", tail: " << q.find_tail() << endl;
  q.print_q();
  
  cout << "is q full?: " << q.is_full() << endl;

  q.dequeue();
  q.dequeue();
  q.print_q();

  q.enqueue(23);
  q.enqueue(6);
  cout << "head: " << q.find_head() << ", tail: " << q.find_tail() << endl;
  q.print_q();

  cout << "is q full? : " << q.is_full() << endl;
  
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.print_q();

  cout << "is q empty? : " << q.is_empty() << endl;

  return 0;
}