#include <iostream>
#include <string>
using namespace std;

// Function to check numeric constant
string isNumericConstant(string input) {
    for (char c : input) {
        if (c < '0' || c > '9') {
            return "Not a numeric constant";
        }
    }
    return "Numeric constant";
}

// Function to check operators
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=');
}

// Function to check single-line comment
bool isSingleLineComment(string line) {
    return line.find("//") == 0;
}

// Function to check multi-line comment
bool isMultiLineComment(string line) {
    return line.find("/*") == 0 && line.rfind("*/") == line.size() - 2;
}

// Function to check identifier
bool isIdentifier(string input) {
    if (input.empty()) return false;
    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
          input[0] == '_')) 
return false;

    for (size_t i = 1; i < input.length(); i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              input[i] == '_')) return false;
    }
    return true;
}

int main() {
    int choice;
    do {
        cout << "\n***Menu***\n";
        cout << "1. Check Numeric Constant\n";
        cout << "2. Find Operators in Expression\n";
        cout << "3. Check if Comment (Single/Multi-line)\n";
        cout << "4. Check Identifier Validity\n";
        cout << "5. Calculate Average of Numbers\n";
        cout << "6. Find Minimum and Maximum of Numbers\n";
        cout << "7. Combine First and Last Name\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string input;
                cout << "Enter a string: ";
                cin >> input;
                cout << isNumericConstant(input) << endl;
                break;
            }
            case 2: {
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
                if (!operatorFound) cout << "No operators found.";
                cout << endl;
                break;
            }
            case 3: {
                string input;
                cout << "Enter a line of code: ";
                getline(cin, input);
                if (isSingleLineComment(input))
                    cout << "This is a single-line comment." << endl;
                else if (isMultiLineComment(input))
                    cout << "This is a multi-line comment." << endl;
                else
                    cout << "This is not a comment." << endl;
                break;
            }
            case 4: {
                string input;
                cout << "Enter an identifier: ";
                cin >> input;
                if (isIdentifier(input))
                    cout << input << " is a valid identifier." << endl;
                else
                    cout << input << " is not a valid identifier." << endl;
                break;
            }
            case 5: {
                int n;
                cout << "Enter number of elements: ";
                cin >> n;
                int arr[n];
                double sum = 0;
                cout << "Enter " << n << " elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                    sum += arr[i];
                }
                cout << "Average value = " << sum / n << endl;
                break;
            }
            case 6: {
                int n;
                cout << "Enter number of elements: ";
                cin >> n;
                int arr[n];
                cout << "Enter " << n << " elements:\n";
                for (int i = 0; i < n; i++) cin >> arr[i];
                int min = arr[0], max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min) min = arr[i];
                    if (arr[i] > max) max = arr[i];
                }
                cout << "Minimum value = " << min << endl;
                cout << "Maximum value = " << max << endl;
                break;
            }
            case 7: {
                string firstName, lastName;
                cout << "Enter your first name: ";
                cin >> firstName;
                cout << "Enter your last name: ";
                cin >> lastName;
                cout << "Full name = " << firstName + " " + lastName << endl;
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
