#include<bits/stdc++.h>
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

bool VI = true;
bool NOVI = false;

vvi graph;
vi visited;

void dfs(int u){
  visited[u] = VI;
  for(int i = 0; i < graph[u].size(); i++){
    int v = graph[u][i];
    if(!visited[v]){
      dfs(v);
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  graph.resize(n);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  visited.resize(n, NOVI);
  vi heads;
  for(int i = 0; i < n; i++){
    if(visited[i] == NOVI){
      dfs(i);
      heads.push_back(i);
    }
  }

  cout << heads.size() - 1 << "\n";
  for(int i = 0; heads.size() - 1 > i; i++){
    cout << heads[i] + 1 << " " << heads[i + 1] + 1 << "\n";
  }
}

