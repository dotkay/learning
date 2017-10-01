#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

class Node {

  int data;
Node* left;
Node* right;

public:
  Node* create_node (int dataitem);
  void insert_node(Node** root, int item);
  bool find_item(Node* root, int item);
  int find_min(Node* root);
  int find_min_r(Node* root);
  int find_height_r(Node* root);
  void bfs(Node* root);
  void dfs_preorder(Node* root);
  void dfs_preorder_r(Node* root);
  void dfs_inorder(Node* root);
  void dfs_inorder_r(Node* root);
  void dfs_postorder(Node* root);
  void dfs_postorder_r(Node* root);
};

Node* Node::create_node (int item) {
  Node* new_node = new Node();
  new_node->data = item;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void Node::insert_node (Node** root, int item) {
  
  // if the tree is empty
  if (*root == NULL) {
    *root = create_node(item);
    return;
  }

  // if the tree is not empty
  // decide where to insert the new node
  else if (item <= (*root)->data)
    insert_node ((&(*root)->left), item);
  
  else
    insert_node (&((*root)->right), item);
}

// look for a given item in the given tree
// return true or false if the item is found/not found
bool Node::find_item(Node* root, int item) {
  // check if the root item is the one
  // we are looking for
  if (root->data == item)
    return true;

  // decide which subtree to search in
  if (item <= root->data) 
    find_item(root->left, item);
  
  else
    find_item(root->right, item);

}

// assume the tree is made of natural
// numbers
int Node::find_min(Node* root) {

  // check if the root node is empty
  if (root == NULL) {
    cout << "No min. element in empty tree!";
    return -1;
  }

  Node* tmp = root;
  while (tmp->left != NULL) {
    tmp = tmp->left;
  }

  return tmp->data;
}

// let's find the min element recursively
int Node::find_min_r(Node* root) {

  // check if the root is empty
  if (root == NULL) {
    cout << "No min. element in empty tree!";
    return -1;
  }

  if (root->left == NULL)
    return root->data;

  return find_min_r(root->left);
}

// find the height of the tree
int Node::find_height_r(Node* root) {
  int left_height, right_height;
  if (root == NULL) {
    return -1;
  }
  left_height = find_height_r(root->left);
  right_height = find_height_r(root->right);
  
  return MAX(left_height, right_height) + 1;
}

// breadth-first-search(bfs) or 
// level-order-traversal of the tree
void Node::bfs(Node* root) {

  // check if the tree is empty
  if (root == NULL) {
    cout << "Empty tree. Nothing to traverse.";
    return;
  }

  // setup a Queue to track Node*s in proper
  // order during our traversal
  queue<Node*> Q;

  // if the current node is not NULL, enqueue it
  // into the Queue
  Q.push(root);

  while(!Q.empty()) {
    // dequeue an element from Q
    Node* curr = Q.front();
    cout << curr->data << " ";

    // check if curr has children
    // if it has, enqueue the children
    if (curr->left != NULL) Q.push(curr->left);
    if (curr->right != NULL) Q.push(curr->right);

    // remove curr from the queue as we have
    // printed it and pushed its children
    Q.pop();
  }

}

// depth-first-search(bfs)  
// DFS could be
//    * Pre-order  : root  - left - right
//    * In-order   : left  - root - right
//    * Post-order : right - root - left
void Node::dfs_preorder_r(Node* root) {

  // check if the tree is empty
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  dfs_preorder_r(root->left);
  dfs_preorder_r(root->right);
}

// Now let's do it without using
// recursion. Instead of the function call
// stack used by our compiler, we will use our
// own stack :-)
void Node::dfs_preorder(Node* root) {

  // check if the given tree is empty
  if (root == NULL) {
    cout << "Empty tree. Nothing to traverse.";
    return;
  }

  // set-up a stack
  stack<Node*> S;
  S.push(root);
  
  while(!S.empty()) {
    Node* curr = S.top();
    cout << curr->data << " ";
    // since we have printed, pop the item
    S.pop();
    
    // push the right subtree followed by the
    // left so that when we pop out of the stack
    // we get the left one first (stack is LIFO)
    if (curr->right != NULL)
      S.push(curr->right);
    if (curr->left != NULL)
      S.push(curr->left);
  }
}

void Node::dfs_inorder(Node* root) {

  if (root == NULL)
    return;
  
  bool done = false;
  stack<Node*> S;
  Node* curr = root;

  while (!done) {

    // move until the left-most node of curr
    // recording all the nodes on the way
    // in our stack
    if (curr != NULL) {
      S.push(curr);
      curr = curr->left;
    }

    // if we reach the end, we pop an element from
    // the stack, print it and set curr to the right
    // sub-tree
    else {
      if (!S.empty()) {
        curr = S.top();
        S.pop();
        cout << curr->data << " ";
        curr = curr->right;
      }

      else { // S is empty, current is NULL
        done = true;
        return;
      }
    }
  }
}

void Node::dfs_inorder_r(Node* root) {

  if (root == NULL)
    return;

  dfs_inorder_r(root->left);
  cout << root->data << " ";
  dfs_inorder_r(root->right);
}

void Node::dfs_postorder(Node* root) {
  bool done = false;
  
  if (root == NULL)
    return;

  stack<Node*> S;
  Node* curr = root;

  while (!done) {

    // go all the way to the right most node in
    // the tree (right subtree) recording the nodes
    // on the way, in our stack
    if (curr != NULL) {
      S.push(curr);
      curr = curr->right;
    }

    else {
      if (!S.empty()) {
        curr = S.top();
        S.pop();
        cout << curr->data << " ";
        curr = curr->left;
      }
      else {
        done = true;
        return;
      }
    }
  }
}

void Node::dfs_postorder_r(Node* root) {

  if (root == NULL)
    return;
  
  dfs_postorder_r(root->right);
  cout << root->data << " ";
  dfs_postorder_r(root->left);
}


int main() {
  Node n;
  Node* bst;
  bst = n.create_node(2);
  n.insert_node(&bst, 1);
  n.insert_node(&bst, 5);
  n.insert_node(&bst, 0);
  n.insert_node(&bst, 3);
  n.insert_node(&bst, 4);
  n.insert_node(&bst, 6);
  n.bfs(bst);
  cout << "\n";
  n.dfs_preorder_r(bst);
  cout << "\n";
  n.dfs_preorder(bst);
  cout << "\nheight of the tree:";
  cout << n.find_height_r(bst);
  cout << "\n";
  n.dfs_inorder_r(bst);
  cout << "\n";
  n.dfs_inorder(bst);
  cout << "\n";
  n.dfs_postorder_r(bst);
  cout << "\n";
  n.dfs_postorder(bst);
  return 0;
}