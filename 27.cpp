// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>& arr,int n)
{
    vector<int> dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
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
    int length=lis(arr,n);
    cout<<length<<endl;
    return 0;
}
