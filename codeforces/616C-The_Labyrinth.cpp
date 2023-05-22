#include <bits/stdc++.h>
using namespace std;

vector< string > graph;
vector< vector< int > > ids;
map< int, int > size_cc;

int amount = 0;
void dfs(int i, int j, int &id) {
  ids[i][j] = id;
  amount++;
  if(i > 0 && graph[i - 1][j] == '.' && ids[i - 1][j] == -1)
    dfs(i - 1, j, id); 
  if(i < (int) graph.size() - 1 && graph[i + 1][j] == '.' && ids[i + 1][j] == -1)
    dfs(i + 1, j, id); 
  if(j > 0 && graph[i][j - 1] == '.' && ids[i][j - 1] == -1)
    dfs(i, j - 1, id); 
  if(j < (int) graph[0].length() - 1 && graph[i][j + 1] == '.' && ids[i][j + 1] == -1)
    dfs(i, j + 1, id); 
}

int main(){
  int n, m;
  cin >> n >> m;
  ids.assign(n, vector< int >(m, -1));
  for(int i = 0; i < n; i++){
    string line;
    cin >> line;
    graph.push_back(line);
  } 

  int id = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(ids[i][j] == -1 && graph[i][j] == '.') {
        amount = 0;
        dfs(i, j, id);
        size_cc[id] = amount;
        id++;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(graph[i][j] == '*') {
        int cc = 1;
        set< int > s;
        if(i > 0 && graph[i - 1][j] == '.')
          s.insert(ids[i - 1][j]);
        if(i < n - 1 && graph[i + 1][j] == '.')
          s.insert(ids[i + 1][j]);
        if(j > 0 && graph[i][j - 1] == '.')
          s.insert(ids[i][j - 1]);
        if(j < m - 1 && graph[i][j + 1] == '.')
          s.insert(ids[i][j + 1]);

        for(auto id : s)
          cc += size_cc[id];
        
        cout << cc % 10;
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }
  return 0;
}
