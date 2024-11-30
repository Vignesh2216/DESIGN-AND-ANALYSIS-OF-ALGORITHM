// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void merge(int n,int m,vector<int>arr1,vector<int>arr2)
{
    map<int,int>freq;
    vector<int>arr;
    for(int i:arr1)
    {
        freq[i]++;
    }
    for(int i:arr2)
    {
        if(freq.find(i)!=freq.end())
        {
            for(int j=0;j<freq[i];j++)
            {
                arr.push_back(i);
            }
        }
        freq.erase(i);
    }
    for(auto it:freq)
    {
        for(int i=0;i<it.second;i++)
        {
            arr.push_back(it.first);
        }
    }
    for(int i:arr)
    {
        cout<<i<<" ";
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    merge(n,m,arr1,arr2);
}