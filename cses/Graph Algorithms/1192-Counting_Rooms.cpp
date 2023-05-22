#include<bits/stdc++.h>
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

vvi graph;
int n, m;

void dfs(int i, int j){
  graph[i][j] = 1;

  if(i > 0 && graph[i - 1][j] == 0) dfs(i - 1, j);
  if(j > 0 && graph[i][j - 1] == 0) dfs(i, j - 1);
  if(i < n - 1 && graph[i + 1][j] == 0) dfs(i + 1, j);
  if(j < m - 1 && graph[i][j + 1] == 0) dfs(i, j + 1);
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    vi row(m);
    for(int j = 0; j < m; j++){
      char c;
      cin >> c;
      row[j] = (c == '#' ? 2 : 0);
    }
    graph.push_back(row);
  }

  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(graph[i][j] == 0){
        dfs(i, j);
        count++;
      }
    }
  }

  cout << count << "\n";
  return 0;
}
