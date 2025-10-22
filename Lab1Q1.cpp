#include <iostream>
using namespace std;

string isNumericConstant(const string input) {
    for (char c : input) {
        if (c < '0' || c > '9') {
            return "Not numeric constant";
        }
    }
    return "Numeric constant";
}


int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    cout << isNumericConstant(input) << endl;

    return 0;
}