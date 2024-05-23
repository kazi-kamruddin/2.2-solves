#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
  
vector<pair<int,int>> graph[N]; 

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

int main() { 
    int node,edge; 
    cin >> node >> edge; 
     
    int v1,v2,wt; 
    for(int i=0 ; i<edge ; i++){ 
      cin >> v1 >> v2 >> wt; 
      
      graph[v1].push_back({v2,wt});
    } 
  
    for(int i=0 ; i<node ; i++){  
      cout << i << " : ";  
      for(int j=0 ; j<graph[i].size() ; j++){  
            cout << graph[i][j].first << " ";  
      }  
      cout << endl;  
    } 
    cout << endl;

    for(int i=0 ; i<node ; i++){
      if(!visDFS[i])
        dfs(i);
    }
    
    cout << "topologically sorted order: ";
    while(!stackDFS.empty()){
      cout << stackDFS.top() << " ";
      stackDFS.pop();
    }
    cout << endl << endl;
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
3 1 4
3 6 3
1 7 3
7 6 4
8 7
*/







