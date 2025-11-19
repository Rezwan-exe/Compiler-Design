#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool validChar(char c) {
    // Valid characters are letters (A-Z, a-z), digits (0-9), or underscore (_)
    return isalnum(c) || c == '_';
}

// Checks if the entire string is a valid identifier 
bool identification(const string& input) {
    if (input.empty())
        return false;

    // Must start with a letter or underscore
    if (!isalpha(input[0]) && input[0] != '_')
        return false;

    // Check remaining characters (must be alphanumeric or underscore, no spaces)
    for (size_t i = 1; i < input.length(); i++) {
        if (!validChar(input[i])) {
            return false; // Found an invalid character (including spaces)
        }
    }

    return true;
}

int main() {
    const string filename = "my_notes.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error: Could not open the file '" << filename << "'" << endl;
        cout << "Please ensure the file exists in the correct location." << endl;
        return 1;
    }

    string line;

    cout << "Identifier Validation Results from: " << filename << endl;
    cout << endl;

    // Read lines one by one and check validity, ignoring line numbers
    while (getline(inputFile, line)) {
        if (identification(line)) {
            cout << "[" << line << "] - VALID Identifier" << endl;
        }
        else {
            cout << "[" << line << "] - INVALID Identifier" << endl;
        }
    }

    inputFile.close();
    return 0;
}