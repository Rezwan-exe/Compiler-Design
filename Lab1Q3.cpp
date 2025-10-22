#include <iostream>
#include <string>
using namespace std;

bool isSingleLineComment(const string& line) {
    return line.find("//") == 0;
} 

bool isMultiLineComment(const string& line) {
    return line.find("/*") == 0 && line.rfind("*/") == line.size() - 2;
}

int main() {
    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);

    if (isSingleLineComment(input)) {
        cout << "This is a single-line comment." << endl;
    }
    else if (isMultiLineComment(input)) {
        cout << "This is a multi-line comment." << endl;
    }
    else {
        cout << "This is not a comment." << endl;
    }

    return 0;
}
