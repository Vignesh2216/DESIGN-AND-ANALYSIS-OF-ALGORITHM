// You are using GCC
#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
bool issafe(int a,int b,int n,int chess[MAX][MAX])
{
    if(a>=0 &&a<n &&b>=0 &&b<n &&chess[a][b]==-1)
    return true;
    else
    return false;
}
bool knight(int n,int a,int b,int count,int chess[MAX][MAX],int x[],int y[])
{
    if(count==n*n)
    return true;
    int next_a,next_b;
    for(int i=0;i<8;i++)
    {
        next_a=a+x[i];
        next_b=b+y[i];
        if(issafe(next_a,next_b,n,chess))
        {
            chess[next_a][next_b]=count;
            if(knight(n,next_a,next_b,count+1,chess,x,y))
            return true;
            else
            chess[next_a][next_b]=-1;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int chess[MAX][MAX];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            chess[i][j]=-1;
        }
    }
    int x[8]={2,1,-1,-2,-2,-1,1,2};
    int y[8]={1,2,2,1,-1,-2,-2,-1};
    chess[0][0]=0;
    if(knight(n,0,0,1,chess,x,y))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    cout<<"Solution does not exist";
    return 0;
}
