// You are using GCC
#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string& str, int L, int R)
{
    while (R > L)
        if (str[L++] != str[R--])
            return false;
    return true;
}

int main()
{
    string str;
    cin >> str;

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    for (auto& query : queries) {
        bool result = isPalindrome(str, query[0], query[1]);
        if (result)
            cout << "The substring [" << query[0] << "," << query[1] << "] is a palindrome" << endl;
        else
            cout << "The substring [" << query[0] << "," << query[1] << "] is not a palindrome" << endl;
    }

    return 0;
}