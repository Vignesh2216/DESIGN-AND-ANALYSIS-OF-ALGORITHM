// You are using GCC
#include<bits/stdc++.h>
using namespace std;
bool issafe(int grid[9][9],int row,int col,int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num || grid[i][col]==num)
            return false;
    }
       row=row-row%3;
       col=col-col%3;
       for(int i=row;i<row+3;i++)
       {
           for(int j=col;j<col+3;j++)
           {
               if(grid[i][j]==num)
               return false;
           }
       }
       return true;
}
bool sudukosolver(int grid[][9],int row,int col)
{
    if(row==8 && col==9)
        return true;
    if(col==9)
    {
        row++;
        col=0;
    }
    if(grid[row][col]!=0)
    {
        return sudukosolver(grid,row,col+1);
    }
    for(int num=1;num<=9;num++)
    {
        if(issafe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(sudukosolver(grid,row,col))
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}
int main()
{
    int grid[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>grid[i][j];
        }
    }
    if(sudukosolver(grid,0,0))
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
           
        }
    }
    else
    cout<<"No solution exists";
}
