#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int d = 256;  // Base value for ASCII characters
const int q = 101;  // A prime number to calculate the hash modulo

// Function to calculate the initial hash for the pattern and the first window of text
int calculateHash(string str, int len) {
    int hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (hash * d + str[i]) % q; // Polynomial hash function
    }
    return hash;
}

// Rabin-Karp Algorithm function
void rabinkarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = calculateHash(pattern, m);
    int textHash = calculateHash(text, m);
    int h = 1;  // Used for rehashing (d^(m-1) % q)

    // Precompute (d^(m-1)) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    bool found = false;
    for (int i = 0; i <= n - m; i++) {
        // Check if the hash values of the pattern and current window of text match
        if (patternHash == textHash) {
            bool match = true;
            // Check character by character
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Found at " << i << endl;
                found = true;
            }
        }

        // Recalculate hash for the next window (rolling hash)
        if (i < n - m) {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % q;
            // We might get negative hash value, converting it to positive
            if (textHash < 0) {
                textHash = (textHash + q);
            }
        }
    }

    if (!found) {
        cout << "Not found" << endl;
    }
}

int main() {
    string text, pattern;
    cin >> text;
    cin >> pattern;
    rabinkarp(text, pattern);
    return 0;
}