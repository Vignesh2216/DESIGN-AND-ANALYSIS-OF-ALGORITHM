// You are using GCC
#include<bits/stdc++.h>
using namespace std;
bool issafe(int node,vector<int>&colors,vector<int>graph[],int color)
{
    for(int neighbour:graph[node])
    {
        if(colors[neighbour]==color)
        {
            return false;
        }
    }
    return true;
}
bool solveMcoloring(int node,int m,vector<int>&colors,vector<int>graph[],int N)
{
    if(node==N)
    return true;
    for(int color=1;color<=m;color++)
    {
        if(issafe(node,colors,graph,color))
        {
            colors[node]=color;
            if(solveMcoloring(node+1,m,colors,graph,N))
            {
                return true;
            }
            colors[node]=0;
        }
    }
    return false;
}
int main()
{
    int n,e,m;
    cin>>n>>e>>m;
    vector<int>graph[n];
    for(int i=0;i<e;++i)
    {
        int u,v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    vector<int>colors(n,0);
    if(solveMcoloring(0,m,colors,graph,n))
    {
        cout<<"Yes"<<endl;
        for(int color:colors)
        {
            cout<<color<<" ";
        }
    }
    else
    {
        cout<<"No"<<endl;
        return 0;
    }
}