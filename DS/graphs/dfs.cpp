// Depth First Search (DFS)

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
  void DFSHelper (int start, bool visited[]);
  public:
    Graph (int v);
    void add_edge (int p, int q);
    void DFS (int start);
};

Graph::Graph (int v) {
  this->v = v;
  adj = new list<int>[v];
}

void Graph::add_edge (int p, int q) {
  adj[p].push_back(q);
}

void Graph::DFSHelper (int start, bool visited[]) {

  // visit the starting node
  visited[start] = true;
  cout << start << " ";

  print_list (adj, start);

  // go to the child nodes one by one
  // depth-wise
  list<int>::iterator i;
  for (i = adj[start].begin(); i != adj[start].end(); i++) {
    if (!visited[*i])
      DFSHelper(*i, visited);
  }
}

void Graph::DFS (int start) {

  // array to mark visited nodes
  bool *visited = new bool[v];

  // initialize visited list to false
  for (int i=0; i<v; i++) {
    visited[i] = false;
  }

  DFSHelper(start, visited);
}
 
int main () {

  /*
  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(2, 3);
  g.add_edge(3, 3);

  g.DFS(2);
  */

  Graph g(6);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 3);
  g.add_edge(1, 4);
  g.add_edge(2, 4);
  g.add_edge(3, 4);
  g.add_edge(3, 5);
  g.add_edge(4, 5);

  g.DFS(0);
  
  return 0;
}