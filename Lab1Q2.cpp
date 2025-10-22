#include <iostream>
#include <string>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=');
}

int main() {
    string input;
    cout << "Enter an expression: ";
    getline(cin, input);

    cout << "Operators found: ";
    bool operatorFound = false;

    for (char ch : input) {
        if (isOperator(ch)) {
            cout << ch << " ";
            operatorFound = true;
        }
    }

    if (!operatorFound) {
        cout << "No operators found.";
    }

    cout << endl;
    return 0;
}