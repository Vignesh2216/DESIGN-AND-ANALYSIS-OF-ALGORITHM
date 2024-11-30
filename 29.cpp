// You are using GCC
#include<bits/stdc++.h>
using namespace std;
bool isSafe(int node,vector<int>&colors,vector<vector<int>>&graph,int color){
    for(int neighbor:graph[node]){
        if(colors[neighbor]==color){
            return false;
        }
    }
    return true;
}
bool solveMColoring(int node,int m,vector<int>&colors,vector<vector<int>>&graph,int N){
    if(node==N){
        return true;
    }
    for(int color=1;color<=m;++color){
        if(isSafe(node,colors,graph,color))
        {
            colors[node]=color;
            if(solveMColoring(node+1,m,colors,graph,N)){
                return true;
            }
            colors[node]=0;
        }
    }
    return false;
}
int main()
{
    int n=4,e=4,m;
    int arr[n][n];
    //vector<int>graph[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cin>>m;
    vector<vector<int>>graph(n);
    vector<int>colors(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            graph[i].push_back(j);
        }
    }
       
    
    if(solveMColoring(0,m,colors,graph,n)){
        cout<<"Solution Exists:"<<endl;
        for(int color:colors){
            cout<<color<<" ";
        }
    }else
    cout<<"Solution does not exist"<<endl;
    return 0;
}