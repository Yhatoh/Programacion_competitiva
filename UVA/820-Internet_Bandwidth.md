## 11045 - My T-Shirt suits me

### Explicación

En este problema, nos hablan de un grafo no dirigido, en el cual entre dos nodos pueden existir varias conexiones con distintos pesos. Y nos piden decir la banda ancha entre dos nodos de la red. Este problema de la banda ancha es exactamente el mismo que resolver maximum flow, por lo que aplicaremos este algoritmo. 

Esta vez, como nos dicen que nos nodos pueden tener varias conexiones, simplemente se unirán todas esas conexiones sumando todos los pesos que haya entre esos dos nodos. Y le pasaremos este grafo al algoritmo de Edmonds Karp.

```c++
while(c--){
    scanf("%d %d %d", &u, &v, &w);
    res[u - 1][v - 1] += w;
    res[v - 1][u - 1] += w;
}
```

De esta forma el maximum flow correspondará a la banda ancha entre los dos nodos que nos den.

Complejidad:

* Construcción grafo: O(c)
* Edmonds Karp's Algorithm: O(V\*E^2)

### Código propuesto

```Cpp
#include<bits/stdc++.h>
using namespace std;

#define MAX_V 100
#define INF 1000000000
typedef vector<int> vi;

int res[MAX_V][MAX_V], mf, f, s, t;
vi p;


void augment(int v, int minEdge){
	if(v == s){
		f = minEdge;
		return;
	}
	else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int main(){
	int n, c, u, v, w, net;
	scanf("%d", &n);
	net = 0;
	while (n != 0) {
		memset(res, 0, sizeof res);

		scanf("%d %d %d", &s, &t, &c);
		while(c--){
			scanf("%d %d %d", &u, &v, &w);
			res[u - 1][v - 1] += w;
			res[v - 1][u - 1] += w;
		}

		s -= 1;
		t -= 1;
		mf = 0;
		while (1) {
			f = 0;
			vi dist(MAX_V, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 0; v < MAX_V; v++){
					if (res[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u] + 1, q.push(v), p[v] = u;
				}
			}
			augment(t, INF);
			if (f == 0)
				break;
			mf += f;
		}
		net++;
		cout << "Network " << net << "\n";
		cout << "The bandwidth is " << mf << ".\n\n";
		scanf("%d", &n);
	}
	return 0;
}
```

