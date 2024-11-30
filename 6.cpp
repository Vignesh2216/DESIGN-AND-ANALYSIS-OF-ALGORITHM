// You are using GCC
#include <bits/stdc++.h>
using namespace std;
#define V 5
void printSolution(int dist[]) {
    cout<<"Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
    printf("%d %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    fill(dist, dist + V, INT_MAX);
    bool sptSet[V];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0,src});
    for (int node = 0;node<V;node++)
    {
        int u = pq.top().second;
        pq.pop();
        sptSet[u] = true;
        for (int i = 0; i < V; i++)
        if (graph[u][i] && !sptSet[i])
        {
            dist[i] = min(dist[i],dist[u]+graph[u][i]);
            pq.push({dist[i],i});
        }
    }
    printSolution(dist);
}
int main() {
    int graph[V][V],s;
    for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
    cin>>graph[i][j];
    cin>>s;
    dijkstra(graph, s);
    return 0;
}