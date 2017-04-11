// Program to check matching of parentheses using a stack

#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool ArePair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;   // all other cases
}

bool IsBalanced(string exp) {
    stack<char> S;
    for (int i = 0; i < exp.length(); i++) {
        // check if it's an opening parenthesis
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        // if it's a closing one
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (S.empty() || !ArePair(S.top(), exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true : false;
}

int main() {
    string test_str;
    cout << "Enter a String:\n";
    cin >> test_str;
    if (IsBalanced(test_str))
        cout << "Balanced!\n";
    else
        cout << "Not Balanced!\n";
    return 0;
}