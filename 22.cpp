// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void bellmanFord(int n,int m,vector<vector<int>>& edges,int source)
{
    vector<int>dist(n+1,INT_MAX);
    dist[source]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(dist[u]!=INT_MAX&& dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INT_MAX)
        {
            cout<<-1<<" ";
        }
        else
        {
            cout<<dist[i]<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges[i]={u,v,w};
    }
    int source;
    cin>>source;
    bellmanFord(n,m,edges,source);
    return 0;
}