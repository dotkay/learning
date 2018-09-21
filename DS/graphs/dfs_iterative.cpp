// Depth First Search (Iterative)
// dfs_iterative.cpp

// This uses an explicit stack rather than a 
// recursive function call (stack) as in dfs.cpp

#include <iostream>
#include <stack>
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
    void DFS (int start);
};

Graph::Graph (int v) {
  this->v = v;
  adj = new list<int>[v];
}

void Graph::add_edge (int p, int q) {
  adj[p].push_back(q);
}

void Graph::DFS (int start) {
  // tracker for visited nodes
  // initialized to false
  bool *visited = new bool[v];
  for (int i=0; i<v; i++)
    visited[i] = false;

  // create a stack to push 
  // the nodes visited
  stack<int> stack;

  // push our starting node
  stack.push(start);

  while (!stack.empty()) {
    // pop the top of stack and 
    // print if not visited
    start = stack.top();
    stack.pop();
    
    if (!visited[start]) {
      cout << start << " ";
      visited[start] = true;
    }

    // get the children of start
    // push them into the stack
    for (auto i = adj[start].begin(); i != adj[start].end(); i++) {
      if (!visited[*i])
        stack.push(*i);
    }
  }

}

int main () {

  Graph g(6);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 3);
  g.add_edge(1, 4);
  g.add_edge(2, 4);
  g.add_edge(3, 4);
  g.add_edge(3, 5);
  g.add_edge(4, 5);

/*
  Graph g(5);
  g.add_edge(1, 0);
  g.add_edge(0, 2);
  g.add_edge(2, 1);
  g.add_edge(0, 3);
  g.add_edge(3, 4);
  g.add_edge(4, 0);
*/
  g.DFS(0);

  return 0;
}