#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10; 
const int INF = 1e9+10; 

int node, edge;
vector<pair<int,int>> graph[N];

vector<int> visited(N, 0);
vector<int> key(N, INF);
vector<int> parent(N, -1);

void prims(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = 1;

        for (auto &[v, weight] : graph[u]) {
            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    
    int total=0;

    cout << "mst edges: " << endl;
    for (int i = 1; i <= node; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << "-" << i << " -> " << key[i] << endl;
            total += key[i];
        }
    }
    
    cout << "Total weight of mst: "  << total << endl;
}

int main() { 
    cin >> node >> edge; 
    
    int v1, v2, wt; 
    for (int i = 0; i < edge; ++i) { 
        cin >> v1 >> v2 >> wt; 
        graph[v1].push_back({v2, wt});
        graph[v2].push_back({v1, wt});
    } 
  
    // for (int i = 1; i <= node; ++i) {  
    //     cout << i << " : ";  
    //     for (int j = 0; j < graph[i].size(); ++j) {  
    //         cout << "(" << graph[i][j].first << ", " << graph[i][j].second << ") ";  
    //     }  
    //     cout << endl;  
    // } 
    // cout << endl;

    int start = 1; 
    prims(start);
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
