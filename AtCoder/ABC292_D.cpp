#include <bits/stdc++.h>
using namespace std;

vector< map< int, int > > G;
vector< int > visited;
set< pair< int, int > > con;
int cant_v = 0;
int cant_e = 0;


void DFS(int u) {
  visited[u] = 1;
  cant_v++;
  for(auto p : G[u]) {
    int v = p.first;
    int amount = p.second;
    if(con.find({u,v}) == con.end() && con.find({v,u}) == con.end()) {
      cant_e += amount;
      con.insert({u,v});
      con.insert({v,u});
    }
    if(!visited[v]) {
      DFS(v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    G.resize(n);
    visited.assign(n, 0);
    while(m--) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      if(u != v)
        G[v][u]++;
      G[u][v]++;
    }
    bool flag = true;
    for(int i = 0; i < n; i++) {
      cant_e = 0;
      cant_v = 0;
      if(visited[i] == 0)
        DFS(i);
      flag = cant_e == cant_v;
      if(flag == false) break;
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
