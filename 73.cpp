// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    cin>>n>>c;
    vector<int>weights(n);
    vector<int>values(n);
    for(int i=0;i<n;i++)
    {
        cin>>weights[i]>>values[i];
    }
    vector<int> dp(c + 1,0);
    for(int i=0;i<n;++i)
    {
        for(int w=c;w>=weights[i];--w)
        {
            dp[w]=max(dp[w],dp[w-weights[i]]+values[i]);
        }
    }
    cout<<dp[c];
}