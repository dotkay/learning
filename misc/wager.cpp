/**
You are a contestant on a TV quiz show. Throughout the game, you and your 2 
opponents have accumulated points by answering trivia questions. At the end 
of the game, the three of you are given one final question. Before you hear 
the question, each contestant must decide how many points he or she wishes 
to wager. Each contestant who answers the question correctly will gain a 
number of points equal to his or her wager, while the others will lose a 
number of points equal to their respective wagers. The contestant who ends 
up with the highest score after the final question wins the game. 

It has come to the point in the game where you must select your wager. You 
can bet any amount between zero and your current score, inclusive. Given 
your current score, the scores of your two opponents, and how much you 
believe each of your opponents will wager, compute how much you should 
wager in order to have the highest probability of winning the game. Assume 
that you and your opponents each independently have a 50% chance of 
answering the final question correctly.

You will be given the three scores as a int[], scores. The first element is 
your score, the next element is your first opponent's score, and the last 
element is your second opponent's score. You will also be given wager1 and 
wager2, the amount of your first and second opponents' wagers, respectively.

Your goal is to maximize your chance of winning uncontested. As far as you're 
concerned, ending in a tie is as bad as losing. If there are multiple wagers 
that give you the same highest probability of winning, return the smallest 
such wager. If you have no chance of winning, return zero.

**/

#include <iostream>
#include <vector>

using namespace std;

class Main {
public:
    int wager(vector<int>, int , int);
};

int Main::wager(vector<int> scores, int wager1, int wager2) {
    int best, bet, odds, wage, i, j, k;
    best = 0; // best bet so far in our iteration
    bet = 0;  // our bet

    // iterate over all allowed wagers we can propose,
    // in order to compute our odds, and the best bet
    for (wage = 0; wage <= scores.at(0); wage++) {
        odds = 0; // compute the number of odds we have
                  // i.e. no. of favourable outcomes
                  // if there's none, we return initial bet, 0.
        for (i = -1; i <= 1; i+=2) 
            for (j = -1; j <= 1; j+=2)
                for (k = -1; k <= 1; k+=2)
                    if (scores.at(0) + i * wage > (scores.at(1) + j * wager1) &&
                        scores.at(0) + i * wage > (scores.at(2) + k * wager2)) {
                            odds++;
                        }
        if (odds > best) {
            bet = wage;    // update our bet
            best = odds;   // update the best odds
        }
    }
    return bet;
}

int main() {
    Main m;
    int bet1, bet2;
    int my_bet;
    vector<int> scores = {0, 0, 0};
    cout << "Enter the scores of you, opponent1 and opponent2 separated by space...\n";
    cin >> scores.at(0) >> scores.at(1) >> scores.at(2);
    cout << "Enter the bets from your opponents\n";
    cin >> bet1 >> bet2;
    my_bet = m.wager(scores, bet1, bet2);
    cout << "your best bet: " << my_bet;
    return 0;
}