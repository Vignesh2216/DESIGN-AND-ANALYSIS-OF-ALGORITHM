// You are using GCC
#include <bits/stdc++.h>
using namespace std;
vector<int> calculateZArray(const string& text) {
    int n = text.length();
    vector<int> z(n, 0);
    int left = 0, right = 0;
    for (int i = 1; i < n; i++) {
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }
        while (i + z[i] < n && text[z[i]] == text[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}

void searchPattern(string pattern, string text) {
    string concat = pattern + "$" + text;
    int patternLength = pattern.length();
    vector<int> zArray = calculateZArray(concat);
    bool found = false;
    for (int i = 0; i < concat.length(); i++) {
        if (zArray[i] == patternLength) {
            cout << "Found at " << (i - patternLength - 1) << endl;
            found = true;
        }
    }
    if(!found)
        cout<<"Not Found"<<endl;
}
int main() {
    string text, pattern;
    cin >> text;
    cin >> pattern;
    searchPattern(pattern, text);
    return 0;
}