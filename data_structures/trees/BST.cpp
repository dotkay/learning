// Binary Search Tree
// C++ implementation

#include <iostream>

template <class Key, class Value>
class BST 
{
  class Node 
  {
    private:
      Key k;
      Value v;
      Node* left;
      Node* right;
      int N;
    // constructor
    private: 
      Node(Key key, Value val, int size);
    friend class BST;
  };  

  private:
    Node* root;
    Node* put_h(Node* x, Key key, Value val);
    Value get_h(Node* x, Key key);
    int size_h(Node* x);

  public:
    BST();
    void put(Key key, Value val);
    Value get(Key key);
    int size();

};

template <class Key, class Value>
BST<Key, Value>::Node::Node(Key key, Value val, int size)
{
  this->k = key;
  this->v = val;
  this->left = NULL;
  this->right = NULL;
  this->N = size;
}

template <class Key, class Value>
BST<Key, Value>::BST()
{
  root = NULL;  
}

template <class Key, class Value>
int BST<Key, Value>::size_h(Node* x)
{
  if (x == NULL)
    return 0;
  return (x->N);
}

template <class Key, class Value>
int BST<Key, Value>::size()
{
  return size_h(root);
}

template <class Key, class Value>
typename BST<Key, Value>::Node* BST<Key, Value>::put_h(Node* x, Key key, Value val)
{
  if (x == NULL)
    return new Node(key, val, 1);
  if (key < x->k)
    x->left = put_h(x->left, key, val);
  else if (key > x->k)
    x->right = put_h(x->right, key, val);
  else
    x->v = val;
  x->N = size_h(x->left) + size_h(x->right) + 1;
  return x;
}

template <class Key, class Value>
void BST<Key, Value>::put(Key key, Value val)
{
  root = put_h(root, key, val);
}

template <class Key, class Value>
Value BST<Key, Value>::get_h(Node* x, Key key)
{
  if (x == NULL)
    return (Value)NULL;
  if (key < x->k)
    return get_h(x->left, key);
  else if (key > x->k)
    return get_h(x->right, key);
  else
    return x->v;
}

template <class Key, class Value>
Value BST<Key, Value>::get(Key key)
{
  return get_h(root, key);
}

int main() 
{
  BST<char, int> bst = BST<char, int>();
  bst.put('a', 1);
  bst.put('b', 2);
  bst.put('c', 3);
  std::cout << "size of bst: " << bst.size() << std::endl;
  std::cout << "value of key 'b': " << bst.get('b') << std::endl;
  
  return 0;
}