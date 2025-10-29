#include <iostream>
#include <string>
using namespace std;

bool isIdentifier (string input) {
    // Empty string
    if (input.empty())
        return false;

    // First character must be alphabet or underscore
    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
          input[0] == '_'))
        return false;

    // Remaining characters must be alphanumeric or underscore
    for (int i = 1; i < input.length(); i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              input[i] == '_'))
            return false;
    }

    return true;
}

int main() {
    string input;

    cout << "Enter an input: ";
    cin >> input;

    if (isIdentifier(input))
        cout << input << " Is a valid Identifier." << endl;
    else
        cout << input << " Is not a valid Identifier." << endl;

    return 0;
}
