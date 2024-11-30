// You are using GCC
#include <bits/stdc++.h>
using namespace std;

string addBinary(string A, string B)
{
    // Ensure A is the smaller string
    if (A.length() > B.length())
        swap(A, B);

    int n = A.length(), m = B.length();
    int diff = m - n;
    string res;
    res.reserve(m + 1);  // Reserve memory for result

    char carry = '0';

    // Iterate from the end of both strings
    for (int i = m - 1; i >= 0; i--) {
        char a = (i - diff >= 0) ? A[i - diff] : '0'; // Get A's current bit or '0' for padding
        char b = B[i];

        if (a == '1' && b == '1') {
            res.push_back(carry);  // Append carry
            carry = '1';  // Carry will always be '1' when both bits are '1'
        }
        else if (a == '0' && b == '0') {
            res.push_back(carry);  // Append carry
            carry = '0';  // Carry remains '0'
        }
        else {
            // One of the bits is '1' and the other is '0'
            res.push_back((carry == '1') ? '0' : '1');  // If carry is '1', result is '0', otherwise '1'
        }
    }

    // If there is still a carry at the end, append it
    if (carry == '1')
        res.push_back('1');

    reverse(res.begin(), res.end());  // Reverse to get the final result in correct order

    // Remove leading zeros
    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    
    return res.substr(index);  // Return the final result starting from the first non-zero character
}

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    cout << addBinary(a, b) << endl;
    return 0;
}