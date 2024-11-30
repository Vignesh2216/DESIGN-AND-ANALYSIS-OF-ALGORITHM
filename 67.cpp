// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    vector<int> arr;
    int num;
    while (cin >> num) 
    {
        arr.push_back(num);
        if (cin.get() == '\n') break;
    }
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> rankMap;
    int rank = 0;
    for (int i = 0; i < sortedArr.size(); i++) 
    {
        if (rankMap.find(sortedArr[i]) == rankMap.end()) 
        {
            rankMap[sortedArr[i]] = rank;
            rank++;
        }
    }
    for (int i = 1; i < arr.size(); i++) 
    {
        cout << rankMap[arr[i]] << " ";
    }
    cout << endl;
    return 0;
}