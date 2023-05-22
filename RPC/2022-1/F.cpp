#include <bits/stdc++.h>
using namespace std;

vector< vector< int > > graph;
int visited;
vector< int > works_done;

void dfs(int u){
  works_done[u] = 1;
  visited += 1;
  for (int j = 0; j < graph[u].size(); j++){
    int v = graph[u][j];
    if (works_done[v] == 0){
      dfs(v);
    }
  }
}

void print(vector< int > &v){
  int i;
  for(i = 0; i < ((int) v.size()) - 1; i++){
    cout << v[i] << " ";
  }
  cout << v[i] << "\n";
}

int main(){
  int n, k;
  cin >> n >> k;

  graph.resize(n);
  works_done.resize(n, 0);

  for(int i = 0; i < n; i++){
    int s;
    cin >> s;
    for(int j = 0; j < s; j++){
      int villager;
      cin >> villager;
      villager--;
      graph[villager].push_back(i);
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      works_done[j] = 0;
    }
    //print(works_done);
    visited = 0;
    dfs(i);
    if(visited > k) cout << 1 << "\n";
    else cout << 0 << "\n";
  }
  return 0;
}