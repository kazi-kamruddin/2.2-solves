#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10; 
const int INF = 1e2+69; 

int node,edge,source;  
bool negCycle = false;
vector<pair<int,int>> graph[N]; 

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
    if((distanceFromSource[v] + wt) < distanceFromSource[child_v]){
      distanceFromSource[child_v] = distanceFromSource[v] + wt;
      predecessor[child_v] = v;
    }
}

void checkNegCycle(){
    for(int v=1 ; v<=node ; v++){
      for(auto child : graph[v]){
        int child_v = child.first;
        int wt = child.second;

        //relax(j,child_v,wt);
        if((distanceFromSource[v] + wt) < distanceFromSource[child_v]){
            negCycle = true;
            break;
        }
      }
    }

    if(negCycle)
      cout << "negative cycle exists." << endl << endl;
    else
      cout << "there isn't any negative cycle." << endl << endl;
}

void bellmanFord(int source){

  singleSourceInit(source);

  for(int i=0 ; i<edge-1 ; i++){
    for(int j=1 ; j<=node ; j++){
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
    bellmanFord(source);

    checkNegCycle();

    // for (int i = 1; i <= node; ++i){
    //   cout <<"for "<<i<<" : "<< distanceFromSource[i] <<" "<< predecessor[i] << endl;
    // }

    for(int i=1;i<=node;i++){
        cout << i << " : ";
        if(distanceFromSource[i] == INF){
          cout << "unreachable from source." << endl;
        }
        else{
          cout<< " cost: "<<distanceFromSource[i]<<" , Path: ";
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

/*
6 7
1 2 5
2 4 2
2 3 1
3 5 1
5 4 -1
4 6 2
6 5 -3
*/







