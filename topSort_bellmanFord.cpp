#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10; 
const int INF = 1e9+10; 
  
vector<pair<int,int>> graph[N]; 

vector<int> dist(N,INF);
map<int,pair<int,int>> nodeStore;
stack<int> path;

bool visDFS[N]; 
stack<int> stackDFS;

void dfs(int vertex){ 

  if(visDFS[vertex]) 
    return; 
  //cout << "vertex: " << vertex << endl;   
  visDFS[vertex] = true;  

  for(auto child : graph[vertex]){ 
    //cout << "par: " << vertex << " child: " << child.first << endl;
    dfs(child.first); 
  }    
  
  stackDFS.push(vertex);
} 

void relax(int v, int child_v,int wt){
    if(dist[v] + wt < dist[child_v]){
      dist[child_v] = dist[v] + wt;
      nodeStore[child_v] = {v,wt};
    }
}

void bellmanFord (int source, int nodeNum, int edgeNum){
  
  for(int i=1 ; i<=nodeNum ; i++){
    nodeStore[i] = {404,404};
  }
  
  nodeStore[source] = {-1,0};
  dist[source] = 0;
  
  for(int i=0 ; i<edgeNum-1 ; i++){
    for(int j=1 ; j<=nodeNum ; j++){
      for(auto child : graph[j]){
        int child_v = child.first;
        int wt = child.second;
  
        relax(j,child_v,wt);
      }
    }
    
  }
}
  
  
int main() { 
    int node,edge; 
    cin >> node >> edge; 
     
    int v1,v2,wt; 
    for(int i=0 ; i<edge ; i++){ 
      cin >> v1 >> v2 >> wt; 
      
      graph[v1].push_back({v2,wt});
    } 
  
    for(int i=1 ; i<=node ; i++){  
      cout << i << " : ";  
      for(int j=0 ; j<graph[i].size() ; j++){  
            cout << graph[i][j].first << " ";  
      }  
      cout << endl;  
    } 
    
    int source,dest,weightSum=0;
    
    cin >> source >> dest;
    
    bellmanFord(source,node,edge);
    
    for(int i=1 ; i<=node ; i++){
      if(!visDFS[i])
        dfs(i);
    }
    
    cout << "topologically sorted order: ";
    while(!stackDFS.empty()){
      cout << stackDFS.top() << " ";
      stackDFS.pop();
    }
    cout << endl << endl;
    
    // for(auto it: nodeStore){
    //   cout << it.first << " e jaite " << it.second.first << " theke weight " << it.second.second << endl;
    // }
    
    if(nodeStore[dest].first == 404){
      cout << endl << "not possible to go from " << source << " to " << dest << endl;
    }
    else{
      while(nodeStore[dest].first != -1){
          weightSum += nodeStore[dest].second;
          //cout << nodeStore[dest].second << " ";
          path.push(dest);
          dest = nodeStore[dest].first;
      }
      path.push(source);
      
      while(!path.empty()){
        cout << " " << path.top() << " ->";
        path.pop();
      }
      cout << ">| " << endl;
      
      cout << "total path weight: " << weightSum << endl;
    }
} 

/*
8 11
4 5 1
4 3 2
4 8 5
5 2 3
5 1 1
8 5 2
8 3 2
3 1 -3
3 6 3
1 7 -5
7 6 4
4 6
*/







