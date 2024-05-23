#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10; 
const int INF = 99; 

int node,edge,source;  
vector<pair<int,int>> graph[N]; 
vector<pair<int,int>> og[N]; 
vector<pair<int,int>> updateOg[N];

int distanceFromSource[N];
int reWeighDist[N];
int predecessor[N];

priority_queue<pair<int,int>> st;
vector<int> visited(N,0);

int dijkDistance[N];
int dijkPre[N];

void dijkSingleSourceInit(int source){
  for(int i=1 ; i<=node ; i++){
    dijkDistance[i] = INF;
    dijkPre[i] = i;
  }
  dijkDistance[source] = 0;
}

void dijkRelax(int v, int child_v,int wt){
    if(dijkDistance[v] + wt < dijkDistance[child_v]){
      dijkDistance[child_v] = dijkDistance[v] + wt;
      st.push({dijkDistance[child_v] , child_v});
      dijkPre[child_v] = v;
    }
}

void dijkstra (int source){
  
  dijkSingleSourceInit(source);
  
  while(!st.empty()) {
    st.pop();
  }
  
  fill(visited.begin(), visited.end(), 0);

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

    for(int i=0 ; i<updateOg[v].size() ; i++){
      pair<int,int> child = updateOg[v][i]; 
      int child_v = child.first;
      int wt = child.second;

      dijkRelax(v,child_v,wt);
    }
  }
}

void dijkPathFinder(int dest){
    if(dijkPre[dest]!=dest){
        dijkPathFinder(dijkPre[dest]);
        cout << "->";
    }
    cout << dest;
}

void singleSourceInit(int source){
  for(int i=0 ; i<=node ; i++){
    distanceFromSource[i] = INF;
    predecessor[i] = i;
  }
  distanceFromSource[source] = 0;
}

void relax(int v, int child_v,int wt){
    if((distanceFromSource[v] + wt) < distanceFromSource[child_v]){
      distanceFromSource[child_v] = distanceFromSource[v] + wt;
      predecessor[child_v] = v;
    }
}

void bellmanFord(int source){

  singleSourceInit(source);

  for(int i=0 ; i<edge-1 ; i++){
    for(int j=0 ; j<=node ; j++){
      for(auto child : graph[j]){
        int child_v = child.first;
        int wt = child.second;
  
        relax(j,child_v,wt);
      }
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
      og[v1].push_back({v2,wt});
    } 
    
    for(int i=1 ; i<=node; i++){
      graph[0].push_back({i,0});     
    }
  
    // for(int i=0 ; i<=node ; i++){  
    //   cout << i << " : ";  
    //   for(int j=0 ; j<graph[i].size() ; j++){  
    //         cout << graph[i][j].first << " ";      
    //   }  
    //   cout << endl;  
    // } 
    // cout << endl;
    
    cin >> source;
    bellmanFord(source);           

    // for (int i = 1; i <= node; ++i){
    //   cout <<"for "<<i<<" : "<< distanceFromSource[i] <<" "<< predecessor[i] << endl;
    // }

    // for(int i=0;i<=node;i++){
    //     cout << i << " : ";
    //     if(distanceFromSource[i] == INF){
    //       cout << "unreachable from source." << endl;
    //     }
    //     else{
    //       cout<< " cost: "<<distanceFromSource[i]<<" , Path: ";
    //       pathFinder(i);
    //       cout<<endl;
    //     }
    // }
    
    // for(int i=0 ; i<=node; i++){
    //   cout<<distanceFromSource[i]<<" ";
    // }
    // cout << endl;
    
    // for(int i=0 ; i<=node ; i++){  
    //   for(int j=0 ; j<og[i].size() ; j++){  
    //         cout << i  << " " << og[i][j].first << " " << og[i][j].second<<endl;     
    //   }  
    // } 
    // cout << endl;
    
    for(int i=0 ; i<=node ; i++){  
      for(int j=0 ; j<og[i].size() ; j++){  
            //cout<< og[i][j].second << " " << distanceFromSource[i] <<" "<<distanceFromSource[og[i][j].first] <<endl;
            int newWeight = og[i][j].second + distanceFromSource[i] - distanceFromSource[og[i][j].first];
            //cout << i << " "<<og[i][j].first << " "<< newWeight << endl;
            updateOg[i].push_back({og[i][j].first,newWeight});
      }  
    }
    cout << endl;
    
    for(int i=1 ; i<=node ; i++){  
      cout << i << " : ";  
      for(int j=0 ; j<og[i].size() ; j++){  
            cout << og[i][j].first << "->" << og[i][j].second << ", ";     
      }  
      cout << endl;  
    } 
    cout << endl;
    
    
    
    for(int i=1 ; i<=node ; i++){  
      cout << i << " : ";  
      for(int j=0 ; j<updateOg[i].size() ; j++){  
            cout << updateOg[i][j].first << "->" << updateOg[i][j].second << ", ";     
      }  
      cout << endl;  
    } 
    cout << endl;
    
    // dijkstra(1);
    
    // for(int i=1;i<=node;i++){
    //     cout << i << " : ";
    //     if(dijkDistance[i] == INF){
    //       cout << "unreachable from source." << endl;
    //     }
    //     else{
    //       cout<<" cost: "<<dijkDistance[i]<<" , Path: ";
    //       dijkPathFinder(i);
    //       cout<<endl;
    //     }
    // }
    
    
    vector<vector<int>> cost(node, vector<int>(node, INF));
    
    for(int i=0 ; i<node ; i++){
      
      dijkstra(i+1);
    
      for(int j=1;j<=node;j++){
        
          cost[i][j-1] = dijkDistance[j];
          
          cout << j << " : ";
          if(dijkDistance[j] == INF){
            cout << "unreachable from source." << endl;
          }
          else{
            cout<<" cost: "<<dijkDistance[j]<<" , Path: ";
            dijkPathFinder(j);
            cout<<endl;
          }
      }
      cout << endl;
    }
    
    cout << "final cost matrix after applying johnson's algo: " << endl << endl;
    
    for(int i=0 ; i<node ; i++){  
      for(int j=0 ; j<node ; j++){  
          if(cost[i][j] == INF)
            cout << "INF" << " ";
          else
            cout << cost[i][j] << " ";
      }  
      cout << endl;  
    } 
    cout << endl;
    
    
} 

/*
6 7
1 2 -2
2 3 -1
3 1 4
3 4 2
3 5 -3
6 4 1
6 5 -4
0
*/

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
0
*/