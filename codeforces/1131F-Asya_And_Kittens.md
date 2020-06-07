## 1131F - Asya and Kittens

### Explicación

En este problema, nos dan la cantidad de gatos n y lo sigue de n - 1 query que corresponden a un gato x y un gato y que quieren jugar juntos. Nos dicen además que en la query i, el gato x_i y y_i deben estar en jaulas adyacentes.

Con esta información se puede observar que el problema corresponde a un problema de unir conjuntos a medida que realizo las query.

Nos piden entregar como posicionariamos cada gato inicialmente para que las condiciones se cumplan.

Para ello, usaremos la estructura de dato disjoint set union (DSU) y un vector extra que mantendrá el conjunto como deberián ir los gatos en cada iteración.

Inicialmente, en el vector que almacena merges almacenamos en la posición i un vector de tamaño 1 que contenga solamente el valor del gato i.

```Cpp
vector< int > gato(1);
for(i = 0; i < n; i++){
	gato[0] = i;
	merges.push_back(chiquito);
}
```

Y ese sería nuestro estado inicial de los conjuntos.

Luego empezamos a leer las query y hacemos unionSet(x - 1, y - 1). Que une los conjuntos como funciona la estructura DSU, pero con un pequeño paso extra donde realiza la unión entre los conjuntos x e y almacenados en merges, donde a x le añadimos y al final si es que rank[x] > rank[y],si no añadimos x en y.

```Cpp
void unionSet(int i, int j){
	if(!isSameSet(i, j)) {
		int x,y;
		x = findSet(i);
		y = findSet(j);

		if(r[x] > r[y]){
			p[y] = x;
			merges[x].insert(merges[x].end(), merges[y].begin(), merges[y].end());
		}
		else {
			p[x] = y;
			merges[y].insert(merges[y].end(), merges[x].begin(), merges[x].end());
			if(r[x] == r[y]) r[y]++;
		}
	}
}
```

Luego de aplicar esta función a cada query, como nos aseguran que siempre existirá una solución, finalmente realizamos la operación findset(0) el cual nos retornará el indice con mayor rank, lo que será el indice del vector merges en que esta una posible solución.

Complejidad:

* Construcción DSU O(1)O(l) = O(l):
	* findSet(i): O(1)
	* union de conjuntos: O(l), donde l es el largo de del conjunto a pegar



### Código propuesto

```Cpp
#include<bits/stdc++.h>

using namespace std;


vector<int> p;
vector<int> r;
vector< vector< int > > merges;

void initUnion(int n){
	int i;
	if(p.size() != 0) p.clear();
	if(r.size() != 0) r.clear();
	for(i = 0; i < n; i++) {
		p.push_back(i);
		r.push_back(0);
	}
}

int findSet(int i){
	return (p[i] == i ? i : (p[i] = findSet(p[i])));
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j){
	if(!isSameSet(i, j)) {
		int x,y;
		x = findSet(i);
		y = findSet(j);

		if(r[x] > r[y]){
			p[y] = x;
			merges[x].insert(merges[x].end(), merges[y].begin(), merges[y].end());
		}
		else {
			p[x] = y;
			merges[y].insert(merges[y].end(), merges[x].begin(), merges[x].end());
			if(r[x] == r[y]) r[y]++;
		}
	}
}

void printUnion(){
	int i;
	for(i = 0; i < p.size(); i++) cout << i + 1 << " " << p[i] + 1<< " " << r[i] << "\n";
}

int main(){
	int n, x, y, BigPapa, i;
	cin >> n;
	initUnion(n);

	vector<int> chiquito(1);
	for(i = 0; i < n; i++){
		chiquito[0] = i;
		merges.push_back(chiquito);
	}

	i = 1;
	while(n > i){
		cin >> x >> y;
		unionSet(x - 1, y - 1);
		i++;
	}


	BigPapa = findSet(0);

	for(i = 0; i < n; i++){

		cout << merges[BigPapa][i] + 1 << "\n";
	}
	return 0;
}
```