// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void print(const vector<vector<int>>& board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
//Function to check if a queen can be placed at board[row][col]
bool isSafe(const vector<vector<int>>&board,int n,int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i]) 
        return false;
    }
    
    for(i = row,j=col ;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]) 
        return false;
    }
    for(i = row,j=col;i<n && j>=0;i++,j--)
    {
        if(board[i][j]) 
        return false;
    }
    return true;

}
bool solveNQutil(vector<vector<int>> &board,int n,int col)
{
    if(col>=n) 
        return true;
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,n,i,col))
        {
            board[i][col] = 1;
            if(solveNQutil(board,n,col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;
}
void solveNQ(int n)
{
    vector<vector<int>>board(n,vector<int>(n,0));
    if(solveNQutil(board,n,0))
    {
        print(board,n);
    }
    else
    {
        cout<<"No solution exists"<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    solveNQ(n);
}