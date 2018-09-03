// queue_simple.cpp

// simple implementation of a queue with a single array
// works but inefficient in space. if the queue is full
// and we dequeue the front element the front location 
// becomes waste as we can not enqueue in there immediately

#include <iostream>
#include <vector>

using namespace std;

class SimpleQ {
  private:
    vector<int> data;
    int head;
  public:
    SimpleQ ();
    bool enqueue (int item);
    bool dequeue ();
    int front ();
    bool is_empty ();
    void print_q ();
};

SimpleQ::SimpleQ () {
  head = 0;
}

bool SimpleQ::enqueue (int item) {
  data.push_back(item);
  return true;
}

bool SimpleQ::is_empty () {
  return (head >= data.size());
}

bool SimpleQ::dequeue () {
  if (this->is_empty()) {
    return false;
  }
  this->head++;
  return true;
}

int SimpleQ::front () {
  return data[head];
}

void SimpleQ::print_q () {
  int size = this->data.size();
  cout << "[ ";
  for (int i=this->head; i<size; i++)
    cout << this->data[i] << " ";
  cout << "]\n";
}

int main () {
  SimpleQ q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.print_q();
  q.dequeue();
  q.print_q();

  return 0;
}