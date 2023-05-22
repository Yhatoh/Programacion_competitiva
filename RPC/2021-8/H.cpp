#include<bits/stdc++.h>
using namespace std;
 
typedef pair<long long, long long> parLarg;
 
int main(){
  ios_base::sync_with_stdio(0); cin.tie();
  //L = C, Q == K
  int n, L, Q;
  cin >> n >> L >> Q;
  vector<vector<pair< int, int>>> graph(n);
  long long a, b, w, u, d, l, v, w2;
  for(int i = 0; i < L; i++){
    cin >> a >> b;
    graph[a].push_back(parLarg(b,1));
    graph[b].push_back(parLarg(a,1));     
  }
 
  vector<int> camino(n, -1);
  vector<long long> encuantollego(n, 1000000000000); 
  encuantollego[Q] = 0;
  priority_queue<parLarg, vector<parLarg>, greater<parLarg>> pQueue;
  pQueue.push(parLarg(0,Q));
  while(!pQueue.empty()){
    w2 = pQueue.top().first;
    u = pQueue.top().second;
 
    pQueue.pop();
 
    if(w2 > encuantollego[u]) continue;
    //if(u == n-1) break;
 
    for(int i = 0; i < graph[u].size(); i++){
      v = graph[u][i].first;
      l = graph[u][i].second;
 
      if(w2 + l < encuantollego[v]){
        camino[v] = u;
        encuantollego[v] = w2+l;
        pQueue.push(parLarg(w2+l,v));
      }
    }
  }
  map< long long, vector< long long > > mapita;

  for(int i = 0; i < n; i++){
    if(i == Q) continue;
    if(encuantollego[i] == 1000000000000) mapita[0].push_back(i);
    else mapita[encuantollego[i]].push_back(i);
  }

  for(auto it = mapita.begin(); it != mapita.end(); it++){
    cout << it->first << ":";
    for(int i = 0; i < it->second.size(); i++){
      cout << " " << it->second[i];
    }
    cout << "\n";
  }
  return 0;
}