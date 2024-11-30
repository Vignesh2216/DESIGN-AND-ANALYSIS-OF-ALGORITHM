// You are using GCC
#include<bits/stdc++.h>
using namespace std;
const int INF = 999;
int V;
void printmatrix(int graph2[][100]){
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph2[i][j] == INF)
            cout << "INF ";
            else
            cout << graph2[i][j] << " ";
        }
        cout << endl;
    }
}
void helper(int graph2[][100], int graph[][100]){
    cout << "Original matrix" << endl;
    printmatrix(graph);
    for(int k=0; k<V; k++)
    for(int i=0; i<V; i++)
    for(int j=0; j<V; j++)
    graph2[i][j] = min(graph2[i][j], graph2[i][k]+graph2[k][j]);
    cout << "Shortest path matrix" << endl;
    printmatrix(graph2);
}
int main()
{
    cin>>V;
    int edges;
    cin>>edges;
    int graph[100][100];
    for(int i=0;i<V;i++){
        for(int j=0; j<V; j++){
            if(i==j){
                graph[i][j] = 0;
            }
            else
            graph[i][j] = INF;
        }
    }
    for(int i=0; i<edges; i++){
        int start, end, value;
        cin>>start>>end>>value;
        graph[start][end] = value;
        graph[end][start] = value;
    }
    int graph2[100][100];
    for(int i=0;i<V;i++)
    for(int j=0; j<V; j++)
    graph2[i][j] = graph[i][j];
    helper(graph,graph2);
}