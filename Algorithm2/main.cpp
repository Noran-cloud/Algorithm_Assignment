#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define loop(n) for(ll i = 0; i < n; i++)
#include <vector>


struct Edge {
    int u, v, weight;
};

bool Compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void union_Sets(int parent[], int rank[], int x, int y) {
    int root_X = find(parent, x);
    int root_Y = find(parent, y);

    if (root_X != root_Y) {
        if (rank[root_X] > rank[root_Y]) {
            parent[root_Y] = root_X;
        } else if (rank[root_X] < rank[root_Y]) {
            parent[root_X] = root_Y;
        } else {
            parent[root_Y] = root_X;
            rank[root_X]++;
        }
    }
}

void kruskal_MST(int V, vector<Edge>& edges) {
    vector<Edge> result;
    int parent[V];
    int rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    sort(edges.begin(), edges.end(), Compare);
    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (find(parent, u) != find(parent, v)) {
            result.push_back(edge);
            union_Sets(parent, rank, u, v);
        }
    }
    cout << "Edges in MST are :\n";
    for (auto& edge : result) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal_MST(V, edges);

    return 0;
}

