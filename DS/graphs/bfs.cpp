// Breadth First Search (BFS)

#include <iostream>
#include <list>

using namespace std;

void print_list (list<int> *lst, int start) {
  list<int>::iterator i;
  cout << "[ ";
  for (i = lst[start].begin(); i != lst[start].end(); i++)
    cout << *i << " ";
  cout << "] \n";
}

class Graph 
{
  int v;          // number of vertices
  list<int> *adj; // adjacency list

  public:
    Graph (int v);
    void add_edge (int p, int q);
    void BFS (int start);
};

Graph::Graph (int v) {
  this->v = v;
  adj = new list<int>[v];
}

void Graph::add_edge (int p, int q) {
  adj[p].push_back(q);
}

void Graph::BFS (int start) {

  // mark all the vertices as not visited
  bool *visited = new bool[v];
  for (int i=0; i<v; i++) {
    visited[i] = false;
  }

  // create a queue for performing BFS
  // the idea is to enqueue vertices into
  // the queue and dequeue them before enquing
  // the connected vertices (from the adj list)
  list<int> queue;

  // mark the starting node 'start' as visited
  // enqueue it into our queue
  visited[start] = true;
  queue.push_back(start);

  // iterator for iterating over the adj list
  list<int>::iterator i;

  while (!queue.empty()) {
    // dequeue an element from the queue
    // and print it
    start = queue.front();
    cout << start << " ";

    print_list (adj, start);

    // remove the element from the queue
    queue.pop_front();

    // get the adjacent vertices by iterating
    // over the adj list
    for (i = adj[start].begin(); i != adj[start].end(); i++) {
      if (!visited[*i]) {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

int main () {

  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(2, 0);
  g.add_edge(3, 3);

  g.BFS(2);

  return 0;
}