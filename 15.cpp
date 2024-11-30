// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int coinChangeWays(vector<int>&coins,int sum)
{
    vector<int>dp(sum+1,0);
    dp[0]=1;
    for(int coin:coins)
    {
        for(int j=coin;j<=sum;j++)
        {
            dp[j]+=dp[j-coin];
        }
    }
    return dp[sum];
}
int main()
{
    int N;
    cin>>N;
    vector<int>coins(N);
    for(int i=0;i<N;i++)
    {
        cin>>coins[i];
    }
    int sum;
    cin>>sum;
    int result=coinChangeWays(coins,sum);
    cout<<result<<endl;
    return 0;
}