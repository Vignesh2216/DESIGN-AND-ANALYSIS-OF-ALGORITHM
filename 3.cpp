// You are using GCC
#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;
void printMST(int parent[], int graph[MAX][MAX], int V) {
    for (int i = 1; i < V; i++)
    cout << parent[i] << " " << i << " " << graph[i][parent[i]] << " \n";
}
void primMST(int graph[MAX][MAX], int V) {
    int parent[V];
    int key[V];
    bool mstSet[V]={false};
    fill(key, key + V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    parent[0] = -1;
    pq.push({0,0});
    for (int count = 0; count < V - 1; count++) {
        int u =pq.top().second;
        pq.pop();
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
                pq.push({key[v],v});
            }
        }
    }
    printMST(parent, graph, V);
}
int main() {
    int V;
    cin >> V;
    int graph[MAX][MAX];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    primMST(graph, V);
    return 0;
}