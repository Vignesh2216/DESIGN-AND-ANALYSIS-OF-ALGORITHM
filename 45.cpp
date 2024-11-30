// You are using GCC
#include<bits/stdc++.h>
using namespace std;
bool canFormWord(const string &s, const string &word) {
    auto it = s.begin();
    for (char c : word) {
        it = find(it, s.end(), c);
        if (it == s.end()) {
            return false; 
        }
        ++it;
    }
    return true;
}
string longestWord(const vector<string> &dictionary, const string &inputString) {
    string longest = "";
    for (const string &word : dictionary) {
        if (canFormWord(inputString, word)) {
            if (word.length() > longest.length()) {
                longest = word; 
            }
        }
    }
    return longest;
}
int main() {
    int size;
    cin >> size;
    vector<string> dictionary(size);
        for (int i = 0; i < size; ++i) {
        cin >> dictionary[i];
    }
        string inputString;
    cin >> inputString;
        string result = longestWord(dictionary, inputString);
    cout << result << endl;
    return 0;
}
