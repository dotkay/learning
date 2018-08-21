// inversion count - simple

#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define REPK(i, k, n) for (int i=k; i<n; i++)

void print_arr (vector<int> arr) {
  int size = arr.size();
  cout << "[ ";
  REP(i, size)
    cout << arr.at(i) << " ";
  cout << "]\n";
}

void print_vp (vector<pair<int, int> > arr) {
  int size = arr.size();
  cout << "[ ";
  REP(i, size)
    cout << "( " << arr.at(i).first << ", " << arr.at(i).second << ") ";
  cout << "]\n";
}

vector<pair<int, int> > count_inv (vector<int> arr) {
  int count = 0;
  int size = arr.size();
  vector<pair<int, int> > inv;
  REP(i, size-1)
    REPK(j, i+1, size)
      if (arr.at(i) > arr.at(j)) {
        count++;
        inv.push_back(make_pair(i, j));
      }
  // Time complexity (O(n^2)) - two for loops    
  return inv;
}

void print_inv (vector<int> arr, vector<pair<int, int> > inv) {
  REP(i, inv.size())
    cout << "(i, j): " << "(" << arr.at(inv.at(i).first) << ", " << arr.at(inv.at(i).second) << ")\n";
}

int main() {
  int n;
  vector<pair<int, int> > inv;

  cout << "Enter the size of the array you need: ";
  cin >> n;
  vector<int> arr(n);
  REP(i, n)
    cin >> arr.at(i);
  
  print_arr(arr);

  inv = count_inv(arr);
  cout << "no. of inversions: " << inv.size() << endl;

  print_inv(arr, inv);

  return 0;
}