#include<bits/stdc++.h>
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

vvi graph;
int n, m;

void dfs(int i, int j, int w){
  int i_1j, i1j, ij_1, ij1; 
  i_1j = i1j = ij_1 = ij1 = 0;
  if(i > 0 && graph[i - 1][j] > w + 1) graph[i - 1][j] = w + 1, i_1j = 1;
  if(j > 0 && graph[i][j - 1] > w + 1) graph[i][j - 1] = w + 1, ij_1 = 1;
  if(i < n - 1 && graph[i + 1][j] > w + 1) graph[i + 1][j] = w + 1, i1j = 1;
  if(j < m - 1 && graph[i][j + 1] > w + 1) graph[i][j + 1] = w + 1, ij1 = 1;

  if(i_1j) dfs(i - 1, j, w + 1);
  if(ij_1) dfs(i, j - 1, w + 1);
  if(i1j) dfs(i + 1, j, w + 1);
  if(ij1) dfs(i, j + 1, w + 1);
}

int main(){
  int start_i, start_j, end_i, end_j;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    vi row(m);
    for(int j = 0; j < m; j++){
      char c;
      cin >> c;
      row[j] = (c == '#' ? -2 : 1000000);
      if(c == 'A'){
        start_i = i;
        start_j = j;
        row[j] = 0;
      } else if(c == 'B'){
        end_i = i;
        end_j = j;
      }
    }
    graph.push_back(row);
  }

  dfs(start_i, start_j, 0);
  
  /*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << graph[i][j] << " ";
    }cout << "\n";
  }cout << "\n";
  */
  if(graph[end_i][end_j] == 1000000) cout << "NO\n";
  else {
    cout << "YES\n";
    cout << graph[end_i][end_j] << "\n";
    string s = "";
    for(int i = end_i, j = end_j; i != start_i || j != start_j;){
      //cout << i << " " << j << "\n";
      if(i > 0 && graph[i - 1][j] == graph[i][j] - 1){
        i = i - 1;
        s = "D" + s;
        continue;
      }
      if(j > 0 && graph[i][j - 1] == graph[i][j] - 1){
        j = j - 1;
        s = "R" + s;
        continue;
      }
      if(i < n - 1 && graph[i + 1][j] == graph[i][j] - 1){
        i = i + 1;
        s = "U" + s;
        continue;
      }
      if(j < m - 1 && graph[i][j + 1] == graph[i][j] - 1){
        j = j + 1;
        s = "L" + s;
        continue;
      }
    }
    cout << s << "\n";
  }
  return 0;
}
