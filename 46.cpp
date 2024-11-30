// You are using GCC
#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(const vector<string>& functionNames) {
    if (functionNames.empty()) return "";
    string prefix = functionNames[0];

    for (int i = 1; i < functionNames.size(); ++i) {
        while (functionNames[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix; 
}
int main() {
    int size;
    cin >> size; 
    cin.ignore(); 

    vector<string> functionNames(size);
    for (int i = 0; i < size; ++i) {
        getline(cin, functionNames[i]); 
    }

    string result = longestCommonPrefix(functionNames);
    if (result.empty()) {
        cout << "No longest prefix found" << endl; 
    } else {
        cout << result << endl;
    }
    return 0;
}

