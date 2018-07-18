/*
Problem: Given an array a[] of size n and a set (array) of queries q[]
of size m, compute the min element in each of the query bounds
Assume that the array a[] is static and each query is of the form
[l, r] - left and right (inclusive) indices of the sub-array to look into
*/

#include <iostream>

using namespace std;

struct Query {
  int L, R;
};

void printIntArray (int a[], int n) {
  cout << "( ";
  for (int i=0; i<n; i++) 
    cout << a[i] << " ";
  cout << ")\n";
}

int minArray (int a[], int l, int r) {
  int min = a[l];
  for (int i=l; i<=r; i++) {
    if (a[i] < min)
      min = a[i];
  }
  return min;
}
void printQuery (Query a[], int n) {
  cout << "[ ";
  for (int i=0; i<n; i++)
    cout << "(" << a[i].L << "," << a[i].R << ") ";
  cout << "]";
}

class Main {
  public:
    void printQueryMin (int*, int, Query*, int);
};

// a : array of elements
// n : size of the array a
// q : set of queries
// m : number of queries
void Main::printQueryMin (int a[], int n, Query q[], int m) {
  int min;
  // traverse each query - O(m)
  for (int i=0; i<m; i++) {
    // get the L, R values
    int L =q[i].L, R = q[i].R;
    // walk through the array a[],
    // picking up the elements within the query bounds
    min = minArray(a, L, R);
    cout << "Min in the query range [" << L << " : " << R << "] = " << min << endl;
  }
  // Total Complexity: O(nm)
}

int main () {
  Main QM;
  int n, m;
  
  // test-case 1
  int a[] = {6, 4, 0, 1, 7, 2, 3, 9, 6};
  n = sizeof(a)/sizeof(a[0]);
  Query q[] = {{0, 4}, {1, 3}, {6, 8}, {3, 6}};
  m = sizeof(q)/sizeof(q[0]);
  cout << "input array:\t";
  printIntArray(a, n);
  cout << "Queries:\t";
  printQuery(q, m);
  cout << "\n";
  QM.printQueryMin(a, n, q, m);

  return 0;
}

