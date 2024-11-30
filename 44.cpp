// You are using GCC
#include <iostream>
using namespace std;
string longestPalindrome(string text)
{
    string T = "#";
    for (char c : text) {
        T += c;
        T += "#";
    }
    int n = T.length();
    int P[n];
    int maxLen = 0;
    int centerIndex = 1;
    P[0] = 0;
    P[1] = 1;
    for (int i = 2; i < n-1; i++)
    {
        int a = i-1;
        int b = i+1;
        P[i] = 0;
        while (T[a] == T[b] && a>=0 && b<n)
        {
            P[i]++;
            a--;
            b++;
        }
        // Update the maximum palindrome found so far
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }//for loop ends
    int start = (centerIndex - maxLen) / 2;  // index in the original string
    return text.substr(start, maxLen);
}

int main() {
    string str;
    cin >> str;
    cout << "LPS of string is " << str << " : " <<longestPalindrome(str);
    return 0;
}