// BFS (using STL queue)

#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <string>

using namespace std;

void print_list (list<int> *lst, int start) {
  cout << "[ ";
  for (auto it = lst[start].begin(); it != lst[start].end(); it++)
    cout << *it << " ";
  cout << "]\n";
}

void print_vec (vector<int> v) {
  cout << "Distance \t [ ";
  for (int i=0; i<v.size(); i++)
    cout << v[i] << " ";
  cout << "]\n";
}

class Graph {
  int v;           // no. of vertices in the graph
  list<int> *adj;  // adjacency list
  vector<int> distance;
  public:
    Graph (int v);
    void add_edge (int p, int q);
    void BFS (int start);

};

Graph::Graph (int v) {
  this->v = v;
  adj = new list<int>[v];
  distance = vector<int>(v);
}

void Graph::add_edge (int p, int q) {
  adj[p].push_back(q);
}

/* BFS using colouring.
Algo:
  - for each node, initialize the colour to white
  - traverse the first node, colour it green
  - enqueue it in our queue
  - while our queue is not empty:
      - dequeue a node
      - traverse the dequeued node's neighbours (from adj list)
      - if they are white, colour them green
*/
void Graph::BFS (int start) {

  // STL queue for enqueueing nodes into
  queue<int> q;
  bool *visited = new bool(v);
  list<int>::iterator i;

  // initialize
  for (int i=0; i<v; i++) {
    visited[i] = false;
    distance[i] = 0;    
  }

  // push the starting node
  // colour it, update the distance
  q.push(start);
  visited[start] = true;
  
  while (!q.empty()) {

    // pop a vertex
    start = q.front();
    cout << start << " ";
    print_list (adj, start);
    print_vec (distance);
    q.pop();

    for (i = adj[start].begin(); i!=adj[start].end(); i++) {
      if (!visited[*i]) {
        // enqueue it to traverse its children
        visited[*i] = true;
        distance[*i] = distance[start]+1;
        q.emplace(*i);
      }
    }
  }
}

int main () {


  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(2, 3);
  g.add_edge(3, 3);

  g.BFS(2);

  Graph g2(6);
  g2.add_edge(0, 1);
  g2.add_edge(0, 2);
  g2.add_edge(1, 3);
  g2.add_edge(1, 4);
  g2.add_edge(2, 4);
  g2.add_edge(3, 4);
  g2.add_edge(3, 5);
  g2.add_edge(4, 5);

  g2.BFS(0);

  return 0;
}