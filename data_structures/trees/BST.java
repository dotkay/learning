// Binary Search Tree
// Java implementation

import java.lang.Comparable;

class BST<Key extends Comparable<Key>, Value> {

  // private members
  private Node root;

  // inner class
  private class Node {
    private Key k;
    private Value v;
    private Node left, right;
    private int N;

    // constructor
    private Node(Key key, Value val, int size) {
      this.k = key;
      this.v = val;
      this.left = null;
      this.right = null;
      this.N = size;
    }
  }

  // constructor
  public BST() {
    root = null;
  }

  // private helper members

  private int size(Node n) {
    if (n == null)
      return 0;
    else
      return n.N;
  }

  private Value get(Node n, Key key) {
    if (n == null) 
      return null;
    int cmp = key.compareTo(n.k);
    if (cmp < 0)
      return get(n.left, key);
    if (cmp > 0)
      return get(n.right, key);
    else
      return n.v;
  }

  private Node put(Node n, Key key, Value val) {
    if (n == null)
      return new Node(key, val, 1);
    int cmp = key.compareTo(n.k);
    if (cmp < 0)
      n.left = put(n.left, key, val);
    else if (cmp > 0)
      n.right = put(n.right, key, val);
    else  
      n.v = val;
    n.N = size(n.left) + size(n.right) + 1;
    return n;
  }

  private Key getMin(Node n) {
    Node x = n;
    if (x == null)
      return null;
    while (x.left != null) {
      x = x.left;
    }
    return x.k;
  }

  private Key getMax(Node n) {
    Node x = n;
    if (x == null)
      return null;
    while (x.right != null) {
      x = x.right;
    }
    return x.k;
  }

  private Node floor(Node n, Key key) {
    if (n == null)
      return null;
    int cmp = key.compareTo(n.k);
    if (cmp == 0)
      return n;
    else if (cmp < 0)
      return floor(n.left, key);
    Node tmp = floor(n.right, key);
    if (tmp != null)
      return tmp;
    else 
      return n;
  }

  private Node ceil(Node n, Key key) {
    if (n == null)
      return null;
    int cmp = key.compareTo(n.k);
    if (cmp == 0)
      return n;
    if (cmp > 0)
      return ceil(n.right, key);
    Node tmp = ceil(n.left, key);
    if (tmp != null)
      return tmp;
    else 
      return n;
  }

  private Node select(Node n, int num) {
    if (n == null)
      return null;
    int lsize = size(n.left);
    if (lsize > num) {
      return select(n.left, num);
    }
    else if (lsize < num) {
      return select(n.right, num - lsize - 1);
    }      
    else 
      return n;
  }

  private Node select_gt(Node n, int num) {
    if (n == null) 
      return null;
    int rsize = size(n.right);
    if (rsize < num)
      return select_gt(n.left, num - rsize - 1);
    else if (rsize > num)
      return select_gt(n.right, num);
    else 
      return n;
  }

  private int rank(Node n, Key key) {
    if (n == null)
      return 0;
    int cmp = key.compareTo(n.k);
    if (cmp < 0) 
      return rank(n.left, key);
    else if (cmp > 0)
      return 1 + size(n.left) + rank(n.right, key);
    else 
      return size(n.left);
  }

  private int rank_gt(Node n, Key key) {
    if (n == null)
      return 0;
    int cmp = key.compareTo(n.k);
    if (cmp < 0) 
      return 1 + rank_gt(n.left, key) + size(n.right);
    else if (cmp > 0)
      return rank_gt(n.right, key);
    else 
      return size(n.right);
  }

  private Node deleteMin(Node n) {
    if (n == null)
      return null;
    if (n.left == null) 
      return n.right;
    n.left = deleteMin(n.left);
    // update N
    n.N = 1 + size(n.left) + size(n.right);
    return n;
  }

  private Node min(Node n) {
    if (n.left == null)
      return n;
    return min(n.left);
  }

  private Node delete(Node n, Key key) {
    if (n == null)
      return null;
    int cmp = key.compareTo(n.k);
    if (cmp < 0) 
      n.left = delete(n.left, key);
    else if (cmp > 0)
      n.right = delete(n.right, key);
    else {
      if (n.right == null)
        return n.left;
      if (n.left == null)
        return n.right;
      Node tmp = n;
      n = min(tmp.right);
      n.right = deleteMin(tmp.right);
      n.left = tmp.left;
    }
    n.N = 1 + size(n.left) + size(n.right);
    return n;
  }

  private void print_inorder(Node n) {
    if (n == null)
      return;
    print_inorder(n.left);
    System.out.print(n.k + " ");
    print_inorder(n.right);
  }

  // public members
  
  public int size() {
    return size(root);
  }

  public Value get(Key key) {
    return get(root, key);
  }

  public void put(Key key, Value val) {
    root = put(root, key, val);
  }

  public Key getMin() {
    return getMin(root);
  }

  public Key getMax() {
    return getMax(root);
  }

  // floor - largest key less than or equal to the given key
  public Key floor(Key key) {
    Node tmp = floor(root, key);
    if (tmp == null)
      return null;
    return tmp.k;
  }

  // ceil - smallest key bigger than or equal to the given key
  public Key ceil(Key key) {
    Node tmp = ceil(root, key);
    if (tmp == null)
      return null;
    return tmp.k;
  }

  // select - return the key such that there are precisely
  //          n keys less than it, given n
  //          select(3) returns a key such that there are exactly
  //          3 keys less than it
  public Key select(int num) {
    Node tmp = select(root, num);
    return tmp.k;
  }

  // select_gt - return the key such that there are precisely
  //             n keys greather than it, given n
  public Key select_gt(int num) {
    Node tmp = select_gt(root, num);
    return tmp.k;
  }

  // rank - return the integer number of keys smaller than
  //        the given key
  public int rank(Key key) {
    return rank(root, key);
  }

  // rank_gt - return the integer number of keys greater than
  //           the given key
  public int rank_gt(Key key) {
    return rank_gt(root, key);
  }

  // deleteMin - delete the minimum key from the bst
  public void deleteMin() {
    root = deleteMin(root);
  }

  // delete - delete a node with the given key
  public void delete(Key key) {
    delete(root, key);
  }

  public void print_inorder() {
    print_inorder(root);
  }

  // driver
  public static void main(String[] args) {
    BST<String, Integer> bst = new BST<String, Integer>();
    bst.put("S", 19);
    bst.put("X", 24);
    bst.put("E", 5);
    bst.put("A", 1);
    bst.put("R", 18);
    bst.put("C", 3);
    bst.put("H", 8);
    bst.put("M", 13);

    System.out.println("size of bst: " + bst.size());
    System.out.println("Min. key in bst: " + bst.getMin());
    System.out.println("Max. key in bst: " + bst.getMax());
    System.out.println("Floor of G: " + bst.floor("G"));
    System.out.println("Ceil of G: " + bst.ceil("G"));
    System.out.println("Select(4) of bst: " + bst.select(4));
    System.out.println("Select_gt(4) of bst: " + bst.select_gt(4));
    System.out.println("Rank(\"R\") of bst: " + bst.rank("R"));
    System.out.println("Rank_gt(\"R\") of bst: " + bst.rank_gt("R"));

    //bst.deleteMin();
    System.out.println("Min. key in bst: " + bst.getMin());
    System.out.println("Size of the bst: " + bst.size());

    bst.print_inorder();
  }
}