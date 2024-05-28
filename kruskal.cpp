#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

int source, node, edge;
vector<pair<int, int>> graph[N];
vector<pair<int, pair<int, int>>> edges;
int parent[N];
int size[N];

void make(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find(int v) {
    if (v == parent[v])
        return v;

    return parent[v] = find(parent[v]); // Path compression
}

void union_(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        if (size[rootA] < size[rootB])   // boro tree er niche choto tree
            swap(rootA, rootB);

        parent[rootB] = rootA;
        size[rootA] += size[rootB];
    }
}

void kruskal(){
    sort(edges.begin(), edges.end());

    int mstWeight = 0;
    for (int i = 1; i <= node; i++) {
        make(i);
    }

    cout << "Edges in mst:" << endl;
    for (auto edge : edges) {
        int wt = edge.first;
        int node1 = edge.second.first;
        int node2 = edge.second.second;

        if (find(node1) != find(node2)) {
            union_(node1, node2);
            mstWeight += wt;
            cout << node1 << "-" << node2 << " -> " << wt << endl;
        }
    }

    cout << "Total weight of mst: " << mstWeight << endl;
}

int main() {
    cin >> node >> edge;

    int v1, v2, wt;
    for (int i = 0; i < edge; i++) {
        cin >> v1 >> v2 >> wt;

        graph[v1].push_back({v2, wt});
        graph[v2].push_back({v1, wt});
        edges.push_back({wt, {v1, v2}});
    }

    kruskal();

    return 0;
}


/*
6 9
1 5 4
1 4 1
1 2 2
5 4 9
4 2 3
4 3 5
2 3 3
2 6 7
3 6 8
*/
