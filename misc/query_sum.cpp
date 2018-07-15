#include <iostream>

using namespace std;

// Query data structure to represent a range
// L and R refer to Left and Right bounds
struct Query {
  int L, R;
};

void printIntArray (int a[], int n) {
  cout << "( ";
  for (int i=0; i<n; i++) 
    cout << a[i] << " ";
  cout << ")\n";
}

void printQuery (Query a[], int n) {
  cout << "[ ";
  for (int i=0; i<n; i++)
    cout << "(" << a[i].L << "," << a[i].R << ") ";
  cout << "]";
}

class Main {
public:
  void printQuerySum(int*, int, Query*, int);
};

// a : array of elements
// n : size of the array a
// q : set of queries
// m : number of queries
void Main::printQuerySum(int a[], int n, Query q[], int m) {
  // This loop: O(m)
  cout << "\n-----------------------------\n";
  for (int i=0; i < m; i++) {
    int L = q[i].L, R = q[i].R;

    // compute the sum of elements in query range
    int sum = 0;
    // this loop: O(n) 
    // (L could be the first element and R the last of a)
    for (int j=L; j<=R; j++) {
      sum += a[j];
    }
    cout << "sum in range [" << L << ", " << R << "] =  " << sum << endl;
  }
  // So, total time complexity is O(nm)
}


int main() {
  Main QS;
  int n, m;
  
  // test-case 1
  int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
  n = sizeof(a)/sizeof(a[0]);
  Query q[] = {{1, 3}, {0, 4}, {2, 4}};
  m = sizeof(q)/sizeof(q[0]);
  cout << "input array:\t";
  printIntArray(a, n);
  cout << "Queries:\t";
  printQuery(q, m);
  QS.printQuerySum(a, n, q, m);

  // test-case 2
  int b[] = {1, 2, 3, 1, 1, 2, 1, 2, 3, 1};
  n = sizeof(b)/sizeof(b[0]);
  Query p[] = {{0, 6}, {1, 3}, {2, 5}};
  m = sizeof(p)/sizeof(p[0]);
  cout << "input array:\t";
  printIntArray(a, n);
  cout << "Queries:\t";
  printQuery(q, m);
  QS.printQuerySum(b, n, p, m);

  return 0;
    
}