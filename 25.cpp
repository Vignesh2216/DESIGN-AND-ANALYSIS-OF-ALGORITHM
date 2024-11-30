// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>& arr)
{
    int n=arr.size();
    vector<int>dp(arr.begin(),arr.end());
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                dp[i]=max(dp[i],dp[j]+arr[i]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<lis(arr);
}