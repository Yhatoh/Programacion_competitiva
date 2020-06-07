## 20C - Dijkstra?

### Explicación

En este problema, nos entregan la cantidad de nodos y aristas, para luego entregarnos las conexiones de los nodos con su peso respectivo. Y nos piden el camino más corto desde el nodo 1 hacia n. Esto es basicamente aplicar dijkstra, pero con un vector extra donde el vector[v] = u, quiere decir que de u puede llegar a v.

Entonces armamos el grafo al comienzo y luego definimos las siguientes estructuras:

```Cpp
//camino es el vector descrito anteriormente
vector<int> camino(n, -1);

//Aqui se almacenera el menor costo para llegar a un nodo v, lo comenzamos en 1000000000000, puesto que ese sería la suma más grande alcanzable.

vector<long long> encuantollego(n, 1000000000000); 
//se inicializa el primero como 0 puesto que para llegar 1 desde 1, es 0
encuantollego[0] = 0;

//este heap nos sirve para aplicar dijkstra
priority_queue<parLarg, vector<parLarg>, greater<parLarg>> pQueue;

//este es el estado inicial para empezar a correr dijkstra
pQueue.push(parLarg(0,0));
```

Luego de definir esto, mientras la cola de prioridad que creamos no este vacia, sacamos el maximo par (peso, nodo), preguntamos si es que ese peso es mayor del que tengo almacenado en encuantollego, esto se debe a que si es que en encuanto llego es menor al peso que saque no me sirve de nada preguntar, ya que estamos buscando el mínimo. También, si es que u es el nodo n paramos de iterar, puesto que si llegamos significa que existe un camino directode 1 hasta n que es mínimo.

Si es que pasa esas dos condiciones, entonces comienzo a iterar por todos los vecinos del nodo que sacamos, por cada vecino preguntamos si es que el peso + el costo de ir desde u a v es menor a lo que tengo almacenado en encuantollego, si es así entonces actualizamos la información de encuantollego y camino, puesto que tenemos un camino más corto para llegar de u a v. Y agregamos a la cola de prioridad el par (peso + el costo de ir desde u a v, v), para seguir iterando.

```Cpp
while(!pQueue.empty()){
	w2 = pQueue.top().first;
	u = pQueue.top().second;

	pQueue.pop();

	if(w2 > encuantollego[u]) continue;
	if(u == n-1) break;

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
```

Cuando esto se termine, si es que lo que esta almacenado es 1000000000000, es porque no se encontro camino. Si existe camino debemos recorrer el vector camino desde n hasta 1 de manera de poder mostar el camino encontrado.

```Cpp
for(int i = n - 1; i != -1; i = camino[i]){
	caminoFinal.push_back(i+1);
}
```

Y así en camino final se encuentra el camino completo y lo mostramos por consola.

Complejidad:

* Construcción grafo: O(|E|)

* Dijsktra: O(|E| + |V|log(|V|)), |E| cantidad de nodos y |V| cantidad de aristas, el logartimo aparece por la utilización del heap. 

### Código propuesto

```Cpp
#include<bits/stdc++.h>
using namespace std;
 
typedef pair<long long, long long> parLarg;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie();
	int n, m;
	cin >> n;
	vector<vector<pair< int, int>>> graph(n);
	cin >> m;
	long long a, b, w, u, d, l, v, w2;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> w;
		graph[a-1].push_back(parLarg(b-1,w));
		graph[b-1].push_back(parLarg(a-1,w));			
	}
 
	vector<int> camino(n, -1);
	vector<int> caminoFinal;
	vector<long long> encuantollego(n, 1000000000000); 
	encuantollego[0] = 0;
	priority_queue<parLarg, vector<parLarg>, greater<parLarg>> pQueue;
	pQueue.push(parLarg(0,0));
	while(!pQueue.empty()){
		w2 = pQueue.top().first;
		u = pQueue.top().second;
 
		pQueue.pop();
 
		if(w2 > encuantollego[u]) continue;
		if(u == n-1) break;
 
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
	//imposible llegar
	if(encuantollego[n-1] == 1000000000000) cout << -1 << "\n";
	else{
		for(int i = n - 1; i != -1; i = camino[i]){
			caminoFinal.push_back(i+1);
		}
		for(int i = caminoFinal.size()-1; i >= 0; i--) cout << caminoFinal[i] <<" ";
		cout << "\n";
	}
	return 0;
}
```