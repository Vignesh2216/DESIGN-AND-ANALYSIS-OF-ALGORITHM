// You are using GCC
#include <bits/stdc++.h>
using namespace std;
bool isSubset(int arr1[], int m, int arr2[], int n) 
{
    unordered_set<int> hashSet;
    for (int i = 0; i < m; i++) 
    {
        hashSet.insert(arr1[i]);
    }
    for (int i = 0; i < n; i++) {
        if (hashSet.find(arr2[i]) == hashSet.end()) 
        {
            return false;
        }
    }
    return true;
}
int main() {
    int m, n;
    cin >> m >> n;
    int arr1[m],arr2[n];
    for (int i = 0; i < m; i++) 
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> arr2[i];
    }
    if (isSubset(arr1, m, arr2, n)) 
    {
        cout << "Subset" << endl;
    } 
    else 
    {
        cout << "Not a subset" << endl;
    }
    return 0;
}