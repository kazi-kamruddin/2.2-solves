#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10; 
const int INF = 1e9+10; 
 
int source,node,edge;  
vector<pair<int,int>> graph[N]; 

priority_queue<pair<int,int>> st;
vector<int> visited(N,0);

int distanceFromSource[N];
int predecessor[N];

void singleSourceInit(int source){
  for(int i=1 ; i<=node ; i++){
    distanceFromSource[i] = INF;
    predecessor[i] = i;
  }
  distanceFromSource[source] = 0;
}

void relax(int v, int child_v,int wt){
    if(distanceFromSource[v] + wt < distanceFromSource[child_v]){
      distanceFromSource[child_v] = distanceFromSource[v] + wt;
      st.push({distanceFromSource[child_v] , child_v});
      predecessor[child_v] = v;
    }
}

void dijkstra (int source){
  
  singleSourceInit(source);

  st.push({0,source});
  
  while(st.size() > 0){
    pair<int,int> node = st.top();
    int v = node.second;
    int v_dist = node.first;
    
    // auto it = st.top();
    // int element = (*it).second;
    //cout << element << endl;
    
    st.pop();
    
    if(visited[v])
      continue;
      
    visited[v] = 1;

    for(int i=0 ; i<graph[v].size() ; i++){
      pair<int,int> child = graph[v][i]; 
      int child_v = child.first;
      int wt = child.second;

      relax(v,child_v,wt);
    }
  }
}

void pathFinder(int dest){
    if(predecessor[dest]!=dest){
        pathFinder(predecessor[dest]);
        cout << "->";
    }
    cout << dest;
}
  
int main() { 
    cin >> node >> edge; 
     
    int v1,v2,wt; 
    for(int i=0 ; i<edge ; i++){ 
      cin >> v1 >> v2 >> wt; 
      
      graph[v1].push_back({v2,wt});
    } 
  
    // for(int i=1 ; i<=node ; i++){  
    //   cout << i << " : ";  
    //   for(int j=0 ; j<graph[i].size() ; j++){  
    //         cout << graph[i][j].first << " ";  
    //   }  
    //   cout << endl;  
    // } 
    // cout << endl;
    
    cin >> source;
    dijkstra(source);

    // for (int i = 1; i <= node; ++i){
    //   cout <<"for "<<i<<" : "<< distanceFromSource[i] <<" "<< predecessor[i] << endl;
    // }
    
    for(int i=1;i<=node;i++){
        cout << i << " : ";
        if(distanceFromSource[i] == INF){
          cout << "unreachable from source." << endl;
        }
        else{
          cout<<" cost: "<<distanceFromSource[i]<<" , Path: ";
          pathFinder(i);
          cout<<endl;
        }
    }
} 

/*
6 9
1 2 6
1 3 4
1 4 5
2 5 -1
3 2 -2
3 5 3
4 3 -2
4 6 -1
5 6 3
1
*/







