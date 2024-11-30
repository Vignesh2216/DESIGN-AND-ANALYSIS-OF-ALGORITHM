// You are using GCC
#include<bits/stdc++.h>
using namespace std;
string longestRepeatingSubstring(string str)
{
    int n=str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    string result="";
    int maxLength=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(str[i-1]==str[j-1]&& dp[i-1][j-1]<(j-i))
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>maxLength)
                {
                    maxLength=dp[i][j];
                    result=str.substr(i-maxLength,maxLength);
                }
            }
        }
    }
    return result;
}
int main()
{
    string str;
    cin>>str;
    string longestSubstring=longestRepeatingSubstring(str);
    cout<<longestSubstring<<endl;
    return 0;
}