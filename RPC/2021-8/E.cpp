#include<bits/stdc++.h>
using namespace std;
vector < vector< int > > adjlist;
vector < bool > visitados;

int no = 0;
int fraternities = 0;
void dfs(int nodoActual){
  visitados[nodoActual] = 1;

  if(adjlist[nodoActual].size() == 0){ no++; fraternities--;}
  //adjlist[nodoActual].size() cuantos vecinos tiene el nodo actual
  for(int i = 0; i < adjlist[nodoActual].size(); i++){
    int vecino = adjlist[nodoActual][i];
    if(visitados[vecino] == 0){
      dfs(vecino);
    }
  }
}

int main(){
  int n, h;
  cin >> n >> h;
  adjlist.resize(n);
  visitados.resize(n);

  for (int i = 0; i < n; ++i){
    visitados[i] = 0;
  }

  for (int i = 0; i < h; ++i){
    int a, b;
    cin >> a >> b;
    adjlist[b - 1].push_back(a - 1);
    adjlist[a - 1].push_back(b - 1);
  }
  for(int i = 0; i < n; i++){
    if(visitados[i] == 0){
      fraternities++;
      dfs(i);
    }
  }
  cout << fraternities << " " << no << "\n";
}
