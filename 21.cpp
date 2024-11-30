// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int mss(int M[][100],int r,int c)
{
    int dp[r][c];
    int Max=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0||j==0){
                dp[i][j]=M[i][j];
            }
            else if(M[i][j]==1){
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
            else{
                dp[i][j]=0;
            }
            Max=max(dp[i][j],Max);
        }
    }
    for(int i=0;i<Max;i++)
    {
        for(int j=0;j<Max;j++)
        {
            cout<<"1 ";
        }
        cout<<endl;
    }
}
int main()
{
    int r,c;
    cin>>r>>c;
    int M[100][100];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>M[i][j];
        }
    }
    mss(M,r,c);
    return 0;
}