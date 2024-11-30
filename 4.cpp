// You are using GCC
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, weight;
};
class UnionFind {
    public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

void findMaxDegreeSpanningTree(int n, int m, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    });
    vector<int> degree(n, 0);
    for (const auto& edge : edges) {
        degree[edge.u]++;
        degree[edge.v]++;
    }
    int max_degree_vertex = max_element(degree.begin(), degree.end()) - degree.begin();
    UnionFind uf(n);
    vector<Edge> mst;
    for (const auto& edge : edges) {
        if (edge.u == max_degree_vertex || edge.v == max_degree_vertex) {
            if (uf.find(edge.u) != uf.find(edge.v)) {
                mst.push_back(edge);
                uf.unite(edge.u, edge.v);
            }
        }
    }
    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            mst.push_back(edge);
            uf.unite(edge.u, edge.v);
        }
    }
    cout << "Spanning Tree Edges (in any order):" << endl;
    for (const auto& edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    findMaxDegreeSpanningTree(n, m, edges);
    return 0;
}