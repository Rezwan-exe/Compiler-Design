#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Function to check if a string is a C++ keyword
bool isKeyword(string s) {
    string keywords[] = {
        "int", "float", "double", "char", "return", "void", "if", "else",
        "for", "while", "do", "switch", "case", "break", "continue"
    };

    for (string k : keywords) {
        if (s == k) return true;
    }
    return false;
}

int main() {
    const string filename = "my_notes2.txt"; // Updated file name
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error: Could not open the file '" << filename << "'" << endl;
        return 1;
    }

    // Read entire file into a single string
    string code, line;
    while (getline(inputFile, line)) {
        code += line + "\n";
    }
    inputFile.close();

    vector<string> tokens;
    string token = "";

    for (int i = 0; i < code.size(); i++) {
        char c = code[i];

        // Letters, digits, underscore → part of identifier or number
        if (isalnum(c) || c == '_') {
            token += c;
        }
        else {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
            }

            if (isspace(c)) continue;

            string symbol(1, c);
            tokens.push_back(symbol);
        }
    }

    // Print tokens with type
    cout << "\nTokens:\n\n";
    for (string t : tokens) {
        if (isKeyword(t)){
            cout << "KEYWORD - " << t << "\n";
        }
        else if (isdigit(t[0])){
            cout << "NUMBER - " << t << "\n";
        }
        else if (isalpha(t[0]) || t[0] == '_'){
            cout << "IDENTIFIER - " << t << "\n";
        }
        else{
            cout << "SYMBOL - " << t << "\n";
        }
    }

    return 0;
}
