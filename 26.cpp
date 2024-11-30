// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int lev(const string& str1, const string& str2)
{
    int m=str1.length();
    int n=str2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                dp[i][j]=i;
            }
            else if(j==0){
                dp[i][j]=j;
            }
            else if(str1[i-1] == str2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]= 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<lev(str1,str2)<<endl;
}