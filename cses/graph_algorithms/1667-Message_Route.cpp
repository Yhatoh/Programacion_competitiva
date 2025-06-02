#include<bits/stdc++.h>
using namespace std;

typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< int > vi;
typedef vector< vii > vvi;

vvi graph;
vi dist;
vi parent;
void print(vector< int > &v){
    int i;
      cout << v.size() << "\n";
        for(i = 0; i < v.size() - 1; i++){
              cout << v[i] << " ";
                }
          cout << v[i] << "\n";
}

void Dijsktra(int s) {
  dist[s] = 0;
  priority_queue<ii, vector< ii >, greater<ii>> pq; 
  pq.push(ii(0, s));

  while(!pq.empty()){
    ii front = pq.top(); pq.pop();
    int d = front.first; int u = front.second;
    if(d > dist[u]) continue;
    //cout << "node: " << u << "->"; 
    for(int j = 0; j < graph[u].size(); j++){
      ii v = graph[u][j];
      //cout << v.first << ", ";
      if(dist[u] + v.second < dist[v.first]){
        dist[v.first] = dist[u] + v.second;
        parent[v.first] = u;
        //cout << v.first << " w " << dist[u] << " " << dist[v.first] << " . ";
        //cout << "dist vec\n";
        //print(dist);
        pq.push(ii(dist[v.first], v.first));
      }
    }
    //cout << "\n";
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  graph.resize(n);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;b--;
    graph[a].push_back(ii(b, 1));
    graph[b].push_back(ii(a, 1));
  }

  dist.resize(n, 10000000);
  parent.resize(n, -1);

  Dijsktra(0);
  //print(dist);
  //print(parent);
  if(dist[n - 1] == 10000000) cout << "IMPOSSIBLE\n";
  else {
    cout << dist[n - 1] + 1 << "\n";
    vi path;
    for(int i = n - 1; i != 0; i = parent[i]){
      //cout << i << " " << parent[i] << "\n";
      path.push_back(i);
    }
    path.push_back(0);
    
    reverse(path.begin(), path.end());
    int i;
    for(i = 0; i < path.size() - 1; i++){
      cout << path[i] + 1 << " "; 
    }
    cout << path[i] + 1 << "\n";  
  }
}
