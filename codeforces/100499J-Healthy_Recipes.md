## 100499J - Healthy Recipes

### Explicación

El problema de Healthy Recipes es ver el problema de contar cuantos sub conjuntos dan la suma M. Ahora, resolver este problema de contar cuantos sub conjuntos dan la suma M, se relaciona con el problema de la mochila 0-1.

Ahora para solucionar este problema, es relacionr la cantidad de subconjuntos que incluyen a la receta i y las recetas que excluyen la receta i. Para llevar a cabo esto, utilizaremos una matriz de N * M, donde uno será para relacionar las calorias de las recetas y el otro la suma en este punto, del siguiente estilo:

```
N 		= 5
M 		= 6
recetas = {2, 4, 5, 1, 3}

  0 1 2 3 4 5 6
2 0 0 0 0 0 0 0
4 0 0 0 0 0 0 0
5 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0
3 0 0 0 0 0 0 0
```

Donde, en un estado inicial ponemos la primera columna tenemos todos los valores con 1, y en la primera fila vemos cual i es igual a las calorias de esa fila quedando el ejemplo anterior de la siguiente forma:

```
  0 1 2 3 4 5 6
2 1 0 1 0 0 0 0
4 1 0 0 0 0 0 0
5 1 0 0 0 0 0 0
1 1 0 0 0 0 0 0
3 1 0 0 0 0 0 0
```

Ahora, hay que comenzar a iterar aplicando la formula que conservamos anteriormente, donde ahora la vamos a generalizar. Entonces, si estamos en la receta i, con la columna j. mochila[i, j] = incluyendo i + excluyendo i. Donde, incluyendo es de la siguente forma mochila[i - 1, j - recetas[i]], puesto que es ver el anterior caso, y usar la columna (que representan la suma) si es que cabe en el conjunto a o no, si j < recestas[i] se suma 0. Ahora excluyendo i es simplemente mochila[i - 1, j], puesto que es la situación donde vemos el caso anterior, pero sin modificar la suma. 

Por lo que quedaría que mochila[i, j] = mochila[i - 1, j - recetas[i]] + mochila[i - 1, j]. Entonces tenemos que hacer un recorrido utilizando un doble for que sea de 2 hasta la cantidad de recetas, puesto que el primer caso lo inicializamos al principio, y otro for de 0 hasta m, representando lo que es lo que sumaría el conjunto.

Entonces al final, depues de varias iteraciones las matriz nos quedaría de la siguiente forma:

```
  0 1 2 3 4 5 6
2 1 0 1 0 0 0 0
4 1 0 1 0 1 0 1
5 1 0 1 0 1 1 1
1 1 1 1 1 1 2 2
3 1 1 1 2 2 3 3
```

Y el valor que se encuentra en la posición 4, 6 sería la cantidad de subconjuntos que entregan la suma 6.

Último detalle a considerar para el problema, como este nos entrega una cota de que si es superior a k, la cantidad de recetas deberiamos dejar de contar, entonces mochila[i, j] = min(mochila[i - 1, j - recetas[i]] + mochila[i - 1, j], k). Y esto solucionaría problemas que hay debido a que la combinación de subconjuntos puede ser muy muy grande.

Ahora, aparte de este desarrollo hay que agregarle un caso inicial, el cual es sacar los 0 de las recetas que nos entregan puesto que nos afecta a nuestro calculo y sabemos que van a ir si os i, entonces por cada 0 que encontramos vamos guardando un contador 2^i, donde i es la cantidad de 0 pillados y los sacamos de ahí. Luego a la respuesta final si es que mochila[n - 1, m] * contador >= k, entonces monstramos enough si no mostramos ese valor.

Complejidad:
* O(N\*M)

### Código propuesto

```Cpp
#include<bits/stdc++.h>

using namespace std;


int main(){
	int t, n, m, k, i, j, count1, count2, a;
	cin >> t;
	while(t--){
		cin >> n >> m >> k;

		long long mochila[103][10005];
		vector< long long > recetas;
		long long count0 = 1;
		
		for(i = 0; i < n; i++){
			cin >> a;
			if(a == 0){ 
				if(count0 <= 100) count0 *= 2;
			}
			else recetas.push_back(a);
		}

		if(recetas.size() > 0){
			for(i = 0; i < recetas.size(); i++) mochila[i][0] = 1;
			for(i = 0; i <= m; i++){
				if(recetas[0] == i){
					mochila[0][i] = 1;
				} else mochila[0][i] = 0;
			}
			mochila[0][0] = 1;
	    
			for(i = 1; i < recetas.size(); i++){
				for(j = 1; j <= m; j++){
					count1 = 0;
					if(recetas[i] <= j){
						count1 = mochila[i - 1][j - recetas[i]];
					}
					count2 = mochila[i - 1][j];
					mochila[i][j] = min(count1 + count2, k);
				}
			}
			if(mochila[recetas.size() - 1][m] * count0 >= k)
				cout << "ENOUGH\n";
			else
				cout << mochila[recetas.size() - 1][m] * count0 << "\n";
		} else {
			if(m != 0) cout << 0 << "\n";
			else if(count0 >= k) cout << "ENOUGH\n";
			else cout << count0 << "\n";
		}
	}
	return 0;	
}
```