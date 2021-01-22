#include<bits/stdc++.h>
using namespace std;

#define INF 1000000

vector < vector< int > > adjlist;
vector < int > distancia;

void bfs(int nodoInicial){
    queue< int > colita;
    distancia[nodoInicial] = 0;
    colita.push(nodoInicial);
    while(!colita.empty()){
        int nodoActual = colita.front();
        colita.pop();
        for(int i = 0; i < adjlist[nodoActual].size(); i++){
            int vecino = adjlist[nodoActual][i];
            if(distancia[vecino] == INF){
                distancia[vecino] = distancia[nodoActual] + 1;
                colita.push(vecino);
            }
        }
    }
}

int main(){
    int t, i;
    cin >> t;
    while(t--){
        int p, d;
        cin >> p >> d;

        adjlist.assign(p, vector< int >());
        distancia.assign(p, INF);

        for(i = 0; i < d; i++){
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        bfs(0);

        for(i = 1; i < p; i++){
            cout << distancia[i] << "\n";
        }

        if(t > 0)
            cout << "\n";
    }
}