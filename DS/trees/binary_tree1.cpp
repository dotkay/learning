// binary trees
// binary_tree1.cpp

#include <iostream>
#include <vector>

using namespace std;

class Node {
  private:
    // members
    int data;
    Node *left;
    Node *right;

    // constructor
    Node (int x);

    friend class BTree;
};

Node::Node (int x) {
  data = x;
  left = NULL;
  right = NULL;
}

class BTree {
  protected:
    Node* root;
    void inorder(const Node *curr) const;
    bool insert(int item, Node *curr);
    void print(Node *curr);
    int min_depth(const Node *curr) const;
  
  public:
    BTree ();
    bool insert(int item);
    void inorder() const;
    void print ();
    int min_depth();
};

BTree::BTree () {
  root = NULL;
}

void BTree::print (Node *curr) {
  if (curr == NULL)
    return;
  cout << curr->data << " ";
  print (curr->left);
  print (curr->right);
}

void BTree::print () {
  print(root);
}

bool BTree::insert (int item) {
  return insert(item, root);
}

void BTree::inorder () const {
  return inorder(root);
}

void BTree::inorder (const Node *curr) const {
  // base case
  if (curr == NULL)
    return;
  
  inorder (curr->left);
  cout << curr->data << " ";
  inorder (curr->right);
}

bool BTree::insert (int item, Node *curr) {
  // base case
  if (root == NULL) {
    root = new Node(item);
    return true;
  }
  // check whether the item is to be
  // added to left or right sub-tree
  else if (item < curr->data) {
    if (curr->left == NULL) {
      curr->left = new Node(item);
      return true;
    }
    else 
      return insert(item, curr->left);
  }
  else if (item > curr->data) {
    if (curr->right == NULL) {
      curr->right = new Node(item);
      return true;
    }
    else 
      return insert(item, curr->right);
  }
  // duplicate node
  else {
    return false;
  }
}

int BTree::min_depth (const Node *root) const {
  // empty tree
  if (root == NULL)
    return 0;

  // one node tree
  if (root->left == NULL && root->right == NULL)
    return 1;
  
  // recur
  if (root->left == NULL)
    return min_depth(root->right) + 1;
  
  if (root->right == NULL)
    return min_depth(root->left) + 1;
  
  return min(min_depth(root->left), min_depth(root->right)) + 1;
}

int BTree::min_depth () {
  return min_depth(root);
}

int main () {
  int n;
  cout << "enter the number of nodes needed: ";
  cin >> n;
  vector<int> nodes(n);
  BTree tree;
  /*
  for (int i=0; i<n; i++) {
    cin >> nodes.at(i);
    tree.insert(nodes.at(i));    
  }
  */

 // let's construct an explicit tree with the 
 // foll shape
 /*
                  1
                /   \
               /     \
              2       3
             / \     / \
            /   \   /   \
           4     5 6     7
 */

  tree.insert(3);
  tree.insert(1);
  tree.insert(2);
  tree.insert(5);
  tree.insert(4);
  tree.insert(7);
  tree.insert(6);

  tree.print();

  cout << "\nin-order traversal: \n";
  tree.inorder();

  cout << "\nmin_depth of tree: " << tree.min_depth() << endl;

  return 0;
}