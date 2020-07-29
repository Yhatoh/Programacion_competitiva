## 11280 - Flying to Fredericton

### Explicación

Este problema nos piden el menor coste de llegar de Calgary hasta Fredericton. La particularidad de este grafo es que es dirigido y nunca te puedes devolver hacia atrás. Y nos dicen que nos preguntaron por el coste mínimo soportando una cantidad máxima de paradas. Y estas pueden ser varias.

Para resolver este problema, nos aprovecharemos del algoritmo de Bellman-Ford.

```Cpp
for(i = 0; i < n - 1; i++){
    for(u = n - 1; u >= 0; u--){
        for(j = 0; j < flights[u].size(); j++){
            a = flights[u][j].first;
            b = flights[u][j].second;
            dist[a] = min(dist[a], dist[u] + b);
        }
    }
}
```

El primer for, correspondería a la cantidad de pasadas a la matriz (donde podrían existir modificaciones). Esto si se ve teóricamente, corresponde a la cantidad máxima que tiene un nodo u para llegar a un nodo v. Entonces, por ejemplo en la primera pasada siempre es vuelo directo (0 paradas), la segunda pasada será el coste pasando por a lo más 1 nodo intermediario (1 pasada) y así. Entonces de esta forma sabemos exactamente el coste mínimo de llegar Calgary hasta Fredericton en cada iteración, valor que iremos guardando.

Finalmente, al momento de realizar las querys simplemente tenemos que preguntar por el índice de los coste y estamos listos (con un índice todo índice mayor a n - 2, será n - 2).

Complejidad:

* Bellman-Ford O(VE)

### Código propuesto

```Cpp
#include<bits/stdc++.h>

using namespace std;


int main(){
	long long t, n, m, i, j, h, cost, q, stopovers, a, b, u;
	string city1, city2;

	cin >> t;
	h = 1;
	while(t >= h){
		map< string, long long > cities;
		cin >> n;
		vector< vector< pair< long long, long long > > > flights(n);
		
		for(i = 0; i < n; i++){
			cin >> city1;
			cities[city1] = i;
		}

		cin >> m;

		for(i = 0; i < m; i++){
			cin >> city1 >> city2 >> cost;

			flights[cities[city1]].push_back(pair<long long, long long>(cities[city2], cost));
		}

		vector< long long > costs(n, INT_MAX);
		vector< long long > dist(n, INT_MAX);
		dist[0] = 0;

		for(i = 0; i < n - 1; i++){
			for(u = n - 1; u >= 0; u--){
				for(j = 0; j < flights[u].size(); j++){
					a = flights[u][j].first;
					b = flights[u][j].second;
					dist[a] = min(dist[a], dist[u] + b);
				}
			}
			costs[i] = dist[n - 1];
		}

		cout << "Scenario #" << h << "\n";

		cin >> q;
		while(q--){
			cin >> stopovers;
			if(stopovers >= n - 1) stopovers = n - 2;

			if(costs[stopovers] == INT_MAX) cout << "No satisfactory flights\n";
			else cout << "Total cost of flight(s) is $" << costs[stopovers] << "\n";
		}
		if(h < t) cout << "\n";
		h++;
	}
	
	return 0;
}
```

