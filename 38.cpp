// You are using GCC
#include <iostream>
#include <string>
using namespace std;
// Function to print all permutations of a string
void permutations(string str, int start, int end) {
    if (start == end) 
    {
        cout << str << endl;  // Print the permutation
    } 
    else 
    {
        for (int i = start; i <= end; i++) 
        {
            // Swap the characters at positions 'start' and 'i'
            swap(str[start], str[i]);
            // Recursively generate permutations for the remaining characters
            permutations(str, start + 1, end);
            // Restore the original order by swapping back
            swap(str[start], str[i]);
        }
    }
}
int main() 
{
    string input;
    cin >> input;
    int n=input.length();
    permutations(input, 0, n - 1);
    return 0;
}