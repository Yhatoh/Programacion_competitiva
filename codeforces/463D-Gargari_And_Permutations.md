## 463D - Gargari and Permutations

### Explicación

En este problema, nos dan k permutaciones de n numeros cada uno, donde estos numeros van de 1 hasta n. Lo que vamos a hacer es crear un grafo dirigido. 

Vamos a decir que i puede llegar a j en el grafo, si y solo si j siempre este despues de i, en todas las permutaciones.

Para ello, vamos a guardar las posiciones de cada i, donde 1 <= i <= n, por permutación mientras vamos leyendo el input. Esto nos servira para poder hacernos la pregunta que planteamos anteriormente.

```Cpp
for(int i = 1; i < n + 1; i++){
	for(int j = 1; j < n + 1; j++){	
		if(i != j){
			int siempreToyDespues = 1;
			for(int h = 0; h < k; h++){
				if(dondeToy[h][i] >= dondeToy[h][j]) {
					siempreToyDespues = 0; 
					break;
				}
			}
			if(siempreToyDespues){
				grafo[i].push_back(j);
			}
		}
	}
}
```

Con el código anterior, añadimos todos los vertices según la condición explicada anteriormente. Donde la variable dondeToy, representa las posiciones de los numeros 1 hasta n dentro de las k permutaciones que nos dan.

En las permutaciones siguientes con n = 4:

1. 1 2 3 4
2. 4 1 2 3
3. 1 2 4 3

| Permutacion  | Pos 1 | Pos 2 | Pos 3 | Pos 4 |
|:------------:|:-----:|:-----:|:-----:|:-----:| 
| 1            | 0     | 1     | 2     | 3     |    
| 2            | 1     | 2     | 3     | 0     |     
| 3            | 0     | 1     | 3     | 2     |     

En esta situación nos quedará un grafo:

```
1 -> 2, 3
2 -> 3 
3 ->
4 ->
```

Como nos dicen que k es a lo más 5 permutaciones y n es a lo más 1000, entonces realizar el proceso mencionado son a lo más 1000 * 1000 * 5 iteraciones. Por lo que en realidad no es tanto.

Ahora aplicamos DFS y de aqui obtendremos el camino más largo del grafo, el correspondera a la subsecuencia más larga. Al ser un grafo dirigido y por como los construimos no tendremos ciclos y siempre se llegará a un nodo sin vecinos.

Y modificamos el algoritmo de DFS de tal forma de tener un arreglo que me almecene el largo del camino que llego acumulado, siempre guardando el valor mayor.

```Cpp
void dfs(int nodo){
	visitado[nodo] = 1;
	for(int i = 0; i < grafo[nodo].size(); i++){
		int v = grafo[nodo][i];
		if(visitado[v] == 0) dfs(v);	
 
		if(largoQueLLevo[nodo] < largoQueLLevo[v] + 1){
			largoQueLLevo[nodo] = largoQueLLevo[v] + 1;
		}
	}
	if(largoQueLLevo[nodo] < 1) largoQueLLevo[nodo] = 1;
}
```

Luego finalmente sacamos el valor más grande que haya adentro del arreglo largoQueLLevo, ya que corresponderá al camino más largo del grafo y correspondientemente la subsecuencia más larga entre las permutaciones.

En el ejemplo mostrado anteriomente el camino más grande es claramente 1 -> 2-> 3

Complejidad: 

* Construccion del grafo es O(k*n^2)

* DFS O(V + E), cantidad de aristas + cantidad de nodos

### Código propuesto

```Cpp
#include<bits/stdc++.h>

using namespace std;

vector< int > visitado(1002, 0);
vector< int > largoQueLLevo(1002, 0);
vector< vector < int > > grafo(1002);
int dondeToy[1002][1002];

void dfs(int nodo){
	visitado[nodo] = 1;
	//eventualmente llegara a un nodo sin vecino en la 
	//primera itereacion
	for(int i = 0; i < grafo[nodo].size(); i++){
		int v = grafo[nodo][i];
		if(visitado[v] == 0) dfs(v);	

		if(largoQueLLevo[nodo] < largoQueLLevo[v] + 1){
			largoQueLLevo[nodo] = largoQueLLevo[v] + 1;
		}
	}
	if(largoQueLLevo[nodo] < 1) largoQueLLevo[nodo] = 1;
}

int main(){
	int n, k, l, masLargo;

	cin >> n >> k;

	if (n == 1){
		cout << 1 << "\n";
		return 0;
	}
	vector< vector < int > > permuts(k);
	
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){	
			cin >> l;
			permuts[i].push_back(l);
			dondeToy[i][l] = j;
		}
	}

	//explicacion tutorial
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < n + 1; j++){	
			if(i != j){
				int siempreToyDespues = 1;
				for(int h = 0; h < k; h++){
					if(dondeToy[h][i] >= dondeToy[h][j]) {siempreToyDespues = 0; break;}
				}
				if(siempreToyDespues){
					grafo[i].push_back(j);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		//cout << i << "\n";
		if(visitado[i] == 0) dfs(i);
	}

	masLargo = 0;

	for(int i = 1; i < n; i++){
		if(masLargo < largoQueLLevo[i]) masLargo = largoQueLLevo[i];
	}
	cout << masLargo << "\n";
	return 0;
}
```