// You are using GCC
#include<bits/stdc++.h>
using namespace std;

int t(int n, int m){
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)
            continue;
            int left=0,up=0;
            if(i-1>=0) left=dp[i-1][j];
            if(j-1>=0) up=dp[i][j-1];
            dp[i][j]=left+up;
        }
    }
    return dp[n-1][m-1];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<t(n,m);
}