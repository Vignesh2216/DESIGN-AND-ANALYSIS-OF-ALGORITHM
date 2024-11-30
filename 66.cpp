// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin >> n;
    vector<int> hashTable(n, -1);
    vector<int> elements(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> elements[i];
    }
    for (int i = 0; i < n; i++) 
    {
        int key = elements[i];
        int hashIndex = key % n;
        while (hashTable[hashIndex] != -1) 
        {
            hashIndex = (hashIndex + 1) % n; 
        }
        hashTable[hashIndex] = key;
    }
    for (int i = 0; i < n; i++) 
    {
        cout << hashTable[i] << " ";
    }
    cout << endl;
    return 0;
}