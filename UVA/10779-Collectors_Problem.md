## 11045 - My T-Shirt suits me

### Explicación

Para poder resolver este problema se aplicará el algoritmo de Edmonds Karp para obtener el maximum flow, puesto que este problema se puede reducir a buscar el máximo flujo de un grafo, pero la mayor dificultad esta en saber como construir ese grafo.

Primero nos fijamos que las restricciones son bastante chicas, pueden haber a lo más 10 personas involucradas y 25 stickers. Entonces crearemos un grafo residual a partir de ello de tamaño n + m, así de esta forma podremos realizar conexiones entre:

* Bob y el sticker j (1 <= j <= m)

  Donde cada conexión entre Bob y un sticker j, tendrá peso la cantidad de veces que tenga bob ese sticker

* Sticker j y persona i (2 <= i <= n)

  Donde si la persona i tiene más de 1 vez el sticker j, entonces se creará la conexión personas i hacia sticker j con peso la cantidad de veces que esa persona tenga ese sticker - 1 (puesto que esa persona se tiene que quedar con 1). Pero si la cantidad de veces que tiene el sticker j es igual a 0, entonces se creará la conexión sticker j hacia persona i con peso 1

```cpp
vi cantStickers(m + 1, 0);
cin >> k;
for(j = 0; j < k; j++){
    cin >> sticker; 
    cantStickers[sticker]++;
}

for(j = 1; j <= m; j++) res[0][j] = cantStickers[j];

//El resto
for(i = 1; i < n; i++){
    vi cantStickers(m + 1, 0);
    cin >> k;
    for(j = 0; j < k; j++){
        cin >> sticker; 
        cantStickers[sticker]++;
    }

    for(j = 1; j <= m; j++){
        if(cantStickers[j] == 0) res[j][m + i] = 1;
        else if(cantStickers[j] > 1) res[m + i][j] = cantStickers[j] - 1;
    }
}
```

De esta forma tenemos listo nuestro grafo residual, donde si buscamos el maximum flow, este corresponderá al máximo número de diferentes stickers que Bob puede obtener a través de intercambios.

Complejidad:

* Construcción grafo: O(n \* m)
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
	int m, n, testCase, cases, i, k, j, sticker;
	cin >> testCase;

	cases = 0;
	while (testCase > cases++) {
		cin >> n >> m;
		memset(res, 0, sizeof res);

		//Bob
		vi cantStickers(m + 1, 0);
		cin >> k;
		for(j = 0; j < k; j++){
			cin >> sticker; 
			cantStickers[sticker]++;
		}

		for(j = 1; j <= m; j++) res[0][j] = cantStickers[j];
		
		//El resto
		for(i = 1; i < n; i++){
			vi cantStickers(m + 1, 0);
			cin >> k;
			for(j = 0; j < k; j++){
				cin >> sticker; 
				cantStickers[sticker]++;
			}

			for(j = 1; j <= m; j++){
				if(cantStickers[j] == 0) res[j][m + i] = 1;
				else if(cantStickers[j] > 1) res[m + i][j] = cantStickers[j] - 1;
			}
		}

		for(i = 1; i <= m; i++) res[i][n + m] = 1;
		
		//res matrix n + m, n + m
		s = 0;
		t = n + m;

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
				for (int v = 0; v < MAX_V; v++)
					if (res[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u] + 1, q.push(v), p[v] = u;
			}
			augment(t, INF);
			if (f == 0)
				break;
			mf += f;
		}

		cout << "Case #" << cases << ": " << mf << "\n";
	}

	
	return 0;
}
```

