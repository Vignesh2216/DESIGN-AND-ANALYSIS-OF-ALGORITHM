#include <bits/stdc++.h>
using namespace std;

int findDistinctPalindromicSubstrings(const string& str, set<string>& result) {
    int n = str.length();
    bool dp[n][n];
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 0)
                dp[i][j] = true; 
            
            else if (gap == 1)
                dp[i][j] = (str[i] == str[j]); 
            
            else
                dp[i][j] = (str[i] == str[j] && dp[i + 1][j - 1]); 
            
            if (dp[i][j])
                result.insert(str.substr(i, j - i + 1));
        }
    }
    return result.size(); 
    
}

int main() {
    string str;
    cin >> str;
    
    set<string> result;
    
    findDistinctPalindromicSubstrings(str, result);
    
    if (!result.empty()) {
        cout << result.size() << endl;
       
        for (const string &s : result)
            cout << s << endl;
    }
    return 0;
}