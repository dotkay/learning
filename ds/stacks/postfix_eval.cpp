// Evaluating a postfix expression using stacks

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// checks if a token is an operator
bool IsOperator(char tok) {
    if (tok == '+' || tok == '-' || tok == '*' || tok == '/')
        return true;
    return false;
}

// checks if a token is a numeric digit
bool IsDigit(char tok) {
    if (tok >= '0' && tok <= '9')
        return true;
    return false;
}


int main() {

    return 0;
}