## 558 - Wormholes

### Explicación

Este problema te pasan un grafo dirigido con pesos positivos y negativos, donde los pesos representan como el tiempo. Entonces, te preguntan si es que existe alguna forma de adquirir tiempo infinito.

Para ello se realiza el siguiente algoritmo, se aplica Bellman-Ford normal en una primera instancia. Y luego posteriormente, se procesa a hacer una iteración extra de Bellman-Ford. Si durante esta iteración extra se encuentra que uno de los tiempos se actualiza, entonces quiere decir que hay un ciclo negativo, puesto que si no lo hubiera no se habría actualizado. Y si este ciclo negativo existe, entonces es posible volver al tiempo infinitamente, si no no es posible.

Complejidad:

* Bellman-Ford: O(VE)

### Código propuesto

```Cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int c, n, m, a, b, t, i, u, j;
	cin >> c;
	while(c--){
		cin >> n >> m;

		vector< vector< pair< int, int > > > starSystem(n);
		i = 0;
		while(m > i++){
			cin >> a >> b >> t;
			starSystem[a].push_back(pair< int, int >(b, t));
		}

		vector< int > dist(n, 3000);
		dist[0] = 0;

		for(i = 0; i < n - 1; i++){
			for(u = 0; u < n; u++){
				for(j = 0; j < starSystem[u].size(); j++){
					a = starSystem[u][j].first;
					b = starSystem[u][j].second;
					dist[a] = min(dist[a], dist[u] + b);
				}
			}
		}

		bool hasNegativeCycle = false;
		for(u = 0; u < n; u++){
			for(j = 0; j < starSystem[u].size(); j++){
				a = starSystem[u][j].first;
				b = starSystem[u][j].second;
				if(dist[a] > dist[u] + b) hasNegativeCycle = true;
				if(hasNegativeCycle) break;
			}
			if(hasNegativeCycle) break;
		}

		if(hasNegativeCycle) cout << "possible\n";
		else cout << "not possible\n";
	}
	
	return 0;
}
```

