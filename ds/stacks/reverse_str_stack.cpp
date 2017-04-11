// Reverse a string using a stack

#include<iostream>
#include<stack>     // stack from STL
#include<cstring>

#define MAX_SIZE 101

using namespace std;

void reverse_string(char C[], int n) {
    stack<char> S;
    for (int i = 0; i < n; i++) {
        S.push(C[i]);
    }
    for (int i = 0; i < n; i++) {
        C[i] = S.top();
        S.pop();
    }
}

void swap(char* i, char* j) {
    char* tmp = i;
    j = tmp;
    i = j;
}

// more space efficient solution
// as we don't use a stack, we 
// don't use the space consumed by
// a stack
void reverse_string_efficient(char C[], int n) {
    int i = 0;
    int j = n-1;
    while (i < j) {
        swap(C[i], C[j]);
        i++; j--;
    }
}

// FIXME: Try with explicit stack and linked list

int main() {
    char C[51];   // our character array representing stack
    cout << "Enter a string:\n";
    cin >> C;
    cout << "Reversed string:\n";
    reverse_string(C, strlen(C));
    cout << C;
    cout << "\nEnter a string again:\n";
    cin >> C;
    reverse_string_efficient(C, strlen(C));
    cout << "Efficiently reversed string:\n";
    cout << C;
    return 0;
}