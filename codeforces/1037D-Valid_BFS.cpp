#include<bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

vi posOrder(1000001);

bool meRevisanAntes(int a, int b){
	return posOrder[a] < posOrder[b];
}

int main(){
	int n, x, y, i, valid, u, v, k;
	cin >> n;
	vvi grafo(n + 1);

	for(i = 0; i < n - 1; i++){
		cin >> x >> y;
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}

	queue< int > secuencia;
	for(i = 0; i < n; i++){
		cin >> x;
		secuencia.push(x);
		posOrder[x] = i;
	}

	for(i = 1; i <= n; i++){
		sort(grafo[i].begin(), grafo[i].end(), meRevisanAntes);
	}

	
	vi visitados(n + 1, 0);
	queue< int > cola;
	visitados[1] = 1;
	cola.push(1);
	valid = 1;

	while(!cola.empty()){
		k = secuencia.front();
		secuencia.pop();
		u = cola.front();
		cola.pop();
		if(k != u){
			valid = 0;
			break;
		}
		for(i = 0; i < grafo[u].size(); i++){

			v = grafo[u][i];
			if(visitados[v] == 0){
				visitados[v] = 1;
				cola.push(v);
			}
		}
	}
	if(valid) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}