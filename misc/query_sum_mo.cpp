/*
The idea behind Mo's algorithm is to process all queries
so that partial results (or results of one query) could
potentially be used in the evaluation of another query
when possible
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

struct Query {
  int L, R;
};

/*
The operational idea is to sort the queries and put them 
in different buckets. The sorting is done is such a way 
that L values from 0 to sqrt(n) are together, sqrt(n) to 
2*sqrt(n)-1 are together, etc. Within each bucket, sort
the queries according to increasing values of R.
You can imagine that there's some preprocessing cost
involved.
*/

int bucket;

// a, b : two Queries to be compared in order to sort
bool compare(Query a, Query b) {
  // first, sort by L if they are in different buckets
  if (a.L/bucket != b.L/bucket)
    return a.L/bucket < b.L/bucket;
  // within the same bucket, queries are sorted
  // according to R values
  return a.R < b.R;
}

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
    void printQuerySumMo (int*, int, Query*, int);
};

/*
Each bucket's size would be of the order of sqrt(n)
where n is the size of the input array of elements.
Queries with L values from 0 - sqrt(n)-1, etc will
stay together, etc.
<0,1,2>,<3,4,5>,<6,7,8> would be the buckets of L values
Within each bucket we will order it according to R values
*/

// a : array of elements
// n : size of the array a
// q : set of queries
// m : number of queries
void Main::printQuerySumMo(int a[], int n, Query q[], int m) {
  // find the bucket size
  bucket = (int)sqrt(n);
  cout << "No. of buckets: " << bucket << "\n";
  // organize the queries into buckets
  sort(q, q + m, compare);
  printQuery(q, m);

  // initialize the current L and R values
  int currL = 0, currR = 0;
  int curr_sum = 0;

  // iterate over the queries
  for (int i=0; i<m; i++) {
    int L = q[i].L, R = q[i].R;
    // taking care of L
    while (currL < L) {
      curr_sum -= a[currL];
      currL++;
    }
    while (currL > L) {
      curr_sum += a[currL];
      currL--;
    }

    // taking care of R
    while (currR <= R) {
      curr_sum += a[currR];
      currR++;
    }
    while (currR > R+1) {
      curr_sum -= a[currR - 1];
      currR--;
    }

    cout << "\nsum in range [" << L << ", " << R << "] =  " << curr_sum;
  }
}


int main () {
  Main QS;
  int n, m;
/*
  // test-case 1
  int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
  n = sizeof(a)/sizeof(a[0]);
  Query q[] = {{1, 3}, {0, 4}, {2, 4}};
  m = sizeof(q)/sizeof(q[0]);
  cout << "input array:\t";
  printIntArray(a, n);
  //cout << "Queries:\t";
  //printQuery(q, m);
  QS.printQuerySumMo(a, n, q, m);

  // test-case 2
  int b[] = {1, 2, 3, 1, 1, 2, 1, 2, 3, 1};
  n = sizeof(b)/sizeof(b[0]);
  Query p[] = {{0, 6}, {1, 3}, {2, 5}};
  m = sizeof(p)/sizeof(p[0]);
  cout << "input array:\t";
  printIntArray(a, n);
  //cout << "Queries:\t";
  //printQuery(q, m);
  QS.printQuerySumMo(b, n, p, m);

*/

  // test-case 3
  int c[] = {1, 2, 3, 1, 1, 2, 4, 1, 3, 4, 2, 1, 2, 3, 4, 1, 1, 3, 4, 2, 3, 2, 1, 2, 3};
  n = sizeof(c)/sizeof(c[0]);
  Query r[] = {{1, 7}, {2, 4}, {0, 8}, {5, 8}, {10, 15}, {18, 21}, {17, 20}, {12, 16}};
  m = sizeof(r)/sizeof(r[0]);
  cout << "input array:\t";
  printIntArray(c, n);
  //cout << "Queries:\t";
  //printQuery(q, m);
  QS.printQuerySumMo(c, n, r, m);

  return 0;
}