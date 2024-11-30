// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    priority_queue<int,vector<int>,greater<>>q;
    for(int i=0;i<n;i++)
    {
        q.push(arr[i]);
    }
    for(int i=1;i<k;i++)
    {
        q.pop();
    }
    cout<<q.top();
}