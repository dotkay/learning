/**
A 100 meter long pipe must be cut in two places. It can only be 
cut at certain places, where it was originally welded from smaller 
pipes. If the two cut locations are chosen at random (each 
potential location has equal probability of being chosen), find the 
probability of a resulting pipe being longer than L meters. 

Create a method named probability that accepts a int[] weldLocations 
and int L as parameters. It should calculate the probability of one 
or more resulting pipes being strictly longer than L if the two cut 
locations are chosen at random from weldLocations. Each element in 
weldLocations represents the number of meters from the left end of 
the pipe.
**/

#include <iostream>
#include <vector>
#include <algorithm> // sort()

using namespace std;

class Main {
public:
  double probability(vector<int>, int);
};

double Main::probability(vector<int> weld_loc, int l) {
  int i, j, no_loc, fav, tot;
  double res;
  no_loc = weld_loc.size();       // no. of weld locations
  tot = no_loc * (no_loc - 1)/2;  // total possibilities
                                  // sample space
  fav = 0;                        // acc to collect fav events
  sort(weld_loc.begin(), weld_loc.end());
  for (i = 0; i < no_loc; i++) {
    for (j = i+1; j < no_loc; j++) {
      int gt_l = 0;  
      // chk if one of the segments of the pipe > l
      // essentially counting the no. of fav. outcomes
      if (weld_loc[i] > l)
        gt_l = 1;
      if (weld_loc[j] - weld_loc[i] > l)
        gt_l = 1;
      if (100 - weld_loc[j] > l)
        gt_l = 1;
      if (gt_l)
        fav++;
    }
  }
  return (double)fav/tot;
}

int main() {
  Main m;
  int n, l;
  double prob;
  cout << "enter the number of weld locations:\n";
  cin >> n;
  vector<int> weld_loc(n);
  cout << "enter the weld locations, separated by space\n";
  for (int i = 0; i < n; i++) {
    cin >> weld_loc.at(i);
  }
  cout << "enter the length of the pipe:\n";
  cin >> l;
  prob = m.probability(weld_loc, l);
  cout << "Probability: " << prob;
  return 0;
}