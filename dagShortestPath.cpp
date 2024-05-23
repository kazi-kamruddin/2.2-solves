#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10; 
const int INF = 1e6+10; 
  
vector<pair<int,int>> graph[N]; 
int node,edge,source; 

bool visDFS[N]; 
stack<int> stackDFS;
vector<int> topOrder;

int distanceFromSource[N];
int predecessor[N];

void dfs(int vertex){ 

  if(visDFS[vertex]) 
    return; 
  //cout << "vertex: " << vertex << endl;   
  visDFS[vertex] = true;  

  //for(auto child : graph[vertex]){
  for(int i=0 ; i<graph[vertex].size() ; i++){
    pair<int,int> child = graph[vertex][i];
    //cout << "par: " << vertex << " child: " << child.first << endl;
    dfs(child.first); 
  }    
  
  stackDFS.push(vertex);
} 

void singleSourceInit(int source){
  for(int i=1 ; i<=node ; i++){
    distanceFromSource[i] = INF;
    predecessor[i] = i;
  }
  distanceFromSource[source] = 0;
}

void topSort(){
  for(int i=1 ; i<=node ; i++){
      if(!visDFS[i])
        dfs(i);
    }
    
    cout << "topologically sorted order: ";
    while(!stackDFS.empty()){
      cout << stackDFS.top() << " ";
      topOrder.push_back(stackDFS.top());
      stackDFS.pop();
    }
    cout << endl << endl;

    // for(auto it: topOrder){
    //   cout << it << " ";
    // }
    cout << endl;
}

void relax(int v, int child_v,int wt){
    if((distanceFromSource[v] + wt) < distanceFromSource[child_v]){
      distanceFromSource[child_v] = distanceFromSource[v] + wt;
      predecessor[child_v] = v;
    }
}

void dagShortestPath(int source){
  topSort();
  singleSourceInit(source);

  for(int i=0 ; i<topOrder.size() ; i++){
    int current = topOrder[i];
    for(auto it: graph[current]){
      relax(current, it.first, it.second);
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

    cin >> source;

    dagShortestPath(source);

    // for (int i = 1; i <= node; ++i){
    //   cout <<"for "<<i<<" : "<< distanceFromSource[i] <<" "<< predecessor[i] << endl;
    // }

    for(int i=1;i<=node;i++){
        cout << i << " : ";
        if(distanceFromSource[i] == INF){
          cout << "unreachable from source." << endl;
        }
        else{
          cout<<i<<") cost: "<<distanceFromSource[i]<<" , Path: ";
          pathFinder(i);
          cout<<endl;
        }
    }
} 

/*
8 11
4 5 1
4 3 2
4 8 5
5 2 3
5 1 1
1 7 3
3 1 4
3 6 3
8 3 2
7 6 4
8 5 2
8
*/