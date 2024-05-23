#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10; 
const int INF = 69;

vector<pair<int,int>> graph[N]; 
int node,edge,source,x;

void printMat(vector<vector<int>> mat){
    for(auto it: mat){
      for(auto i: it){
        cout << i << " ";
      }
      cout << endl;
    }
    cout << endl;
}

void allSourceInit(vector<vector<int>> &cost, vector<vector<int>> &predecessor) {
  for(int i=0; i<node; i++){
    for(int j=0; j<node; j++){ 
      cost[i][j] = INF;  
      predecessor[i][j] = -1; 
      if(i==j) cost[i][j] = 0;  
    } 
  }

  for(int i=1; i<=node; i++){
    for(int j=0; j<graph[i].size(); j++){ 
      int src=i-1, dest=graph[i][j].first-1, wt=graph[i][j].second;
      cost[src][dest] = wt;
      predecessor[src][dest] = src+1;
    } 
  } 
}

void warshall(int x, vector<vector<int>> &cost, vector<vector<int>> &predecessor){
    allSourceInit(cost,predecessor); 

    for(int k=0; k<x; k++){
      vector<vector<int>> copy = cost;

      for(int i=0; i<node; i++){
        for(int j=0; j<node; j++){ 
          if(cost[i][k]+cost[k][j] < copy[i][j]){
              cost[i][j] = min(copy[i][j], cost[i][k]+cost[k][j]);
              predecessor[i][j] = predecessor[k][j];
          }
        }
      }

      // printMat(cost);
      // printMat(predecessor);
    }
}

int main() {
    cin >> node >> edge; 
     
    int v1,v2,wt; 
    for(int i=0 ; i<edge ; i++){ 
      cin >> v1 >> v2 >> wt; 
      
      graph[v1].push_back({v2,wt});
    } 
  
    for(int i=1 ; i<=node ; i++){  
      cout << i << ": ";  
      for(int j=0 ; j<graph[i].size() ; j++){  
            cout << graph[i][j].first << " ";  
      }  
      cout << endl;  
    } 
    cout << endl;

    vector<vector<int>> cost(node, vector<int>(node, INF));
    vector<vector<int>> predecessor(node, vector<int>(node, -1));
    
    cin >> x;
    warshall(x,cost,predecessor);

    cout << "final cost matrix: " << endl;
    printMat(cost);
    cout << "final predecessor matrix: " << endl;
    printMat(predecessor);
}

/*
5 9
1 2 3
1 3 8
1 5 -4
2 5 7
2 4 1
3 2 4
4 1 2
4 3 -5
5 4 6
5
*/