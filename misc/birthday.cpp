#include <iostream>

using namespace std;

class Main {
public:
  int min_people(int, int);
};

// given the odds, compute the min. number
// of people to achieve this prob (odds)
int Main::min_people(int odds, int days) {
  int fav;     // no. of fav events
  double prob; // probability that the odds will be met

  fav = 1;
  prob = 1.0;
  for (int i = 0; i < days; i++) {
    prob = prob * ((double) (days - i)/days);
    cout << "prob: " << prob << "\n";
    if ((prob * 100) < (100 - odds)) {
      cout << "prob: " << prob << "\n";
      break;
    }
    fav++;
  }
  return fav;
}

int main() {
  Main m;
  int min_odds, days;
  int result;
  cout << "Enter the min odds and days separated by a space:\n";
  cin >> min_odds >> days;
  result = m.min_people(min_odds, days);
  cout << "Result: " << result;
  return 0;
}