## 928D - Shark

### Explicación

En este problema nos entregan una cantidad de n dias y en cada día el tiburón recorre una distancia d. Max asume que existe un k de tal forma en que si d >= k, el tiburón se mueve de lugar, si no se queda en el lugar. Asumiendo que el tiburón nunca se moverá a un lugar en el cual ya estuvo. Nos piden determinar el menor k de tal forma que el tiburón haya visitado la mayor cantidad de lugares posibles, pero una condición: 

* El tiburón se debe haber quedado la misma cantidad de dias en cada lugar. 

Si vemos el problema, este corresponde a un problema de un union de conjuntos, pero no utilice directamente la estructura como tal. 

Para resolver esto primero, recibiremos las n distancias y crearemos pares de (d, i) donde i es su posición en la lista de distancias, y procedemos a ordenarlas de menor a mayor distancia.

```Cpp
vector< pair< int, int > > viajes;

for(i = 0; i < n; i++){
	cin >> d;
	viajes.push_back(pair< int, int >(d, i + 1));
}
```

Usemos un ejemplo, para poder ilustrar mejor el funcionamiento del algoritmo.
```
Input:
6
1 2 7 3 4 8

Estado inicial

viajes					[(1, 1), (2, 2), (3, 4) (4, 5), (7, 3), (8, 6)]
localizaciones			|0, 0, 0, 0, 0, 0|
cantidad localizaciones 0


Primera Iteración
	(1, 1)

	Marco la posición 1
	localizaciones |1, 0, 0, 0, 0|

	Como hay 1 localizacion, k = 1 + 1 = 2, puesto que el tiburón que se quedará en esta localizacion

	y la cantidad de localizaciones de este k son 1


Segunda Iteración

	(2, 2)	

	Marco la posición 2
	localizaciones |1, 1, 0, 0, 0, 0|

	Ahora tengo nuevamente 1 localización pero de tamaño dos, pero como me piden el k más chico no actualizo nada

Tercera Iteración

	(3, 4)	

	Marco la posición 4
	localizaciones |1, 1, 0, 1, 0, 0|

	Ahora tengo dos localizaciones, pero son de distinto tamaño así que tampoco actualizamos nada.

Cuarta Iteración
	
	(4, 5)

	Marco la posición 5
	localizaciones |1, 1, 0, 1, 1, 0|

	Ahora tenemos dos localizaciones y del mismo largo :D.
	Como tenemos dos localizaciones (que es mayor a la cantidad de localizaciones del k anterior que habiamos encontrado)

	Por lo que la cantidad localizaciones será 2 y k = 4 + 1 = 5, puesto que de esta forma el tiburón se quedará quieto en los dias 1,2 y 3,4

Quinta Iteración

	(7, 3)

	Marco la posición 3
	localizaciones |1, 1, 1, 1, 1, 0|

	Tenemos una localización ahora, lo que es menor a la cantidad de localizaciones encontradas anteriormente por lo que no hacemos cambio.

Sexto Iteración

	(8, 6)

	Marco la posición 6
	localizaciones |1, 1, 1, 1, 1, 1|

	Tenemos una localización ahora, lo que es menor a la cantidad de localizaciones encontradas anteriormente por lo que no hacemos cambio.

Entregandonos como respuesta k = 5
```

Para poder programar lo anterior, tendremos dos vectores llamados finalInter y beginInter que nos permitirán donde comienza y termina los conjuntos, de manera que podemos unirlos posteriormente. Donde finalInter[i] tendrá la posición de donde termina el conjunto en que pertenece i y beginInter[i] tendrá la posición de donde comienza el conjunto en que pertenece i. Si el valor es 0 es porque no pertenece a ningún conjunto.

### Código propuesto

```Cpp
#include<bits/stdc++.h>

using namespace std;

vector< int > finalInter;
vector< int > beginInter;

int maxLength;
int mismoLargo;
int cantsLocs;
int cantMaxLengthLocs;

void unionSet(int i, int j, int rest){
	int actualLength = j - i + 1;
	if(rest > 0) cantsLocs -= rest;

	//A que intervalo pertenece idea DSU
	finalInter[j] = i;
	beginInter[i] = j;
	cantsLocs++;

	if(actualLength > maxLength){
		maxLength = actualLength;
		cantMaxLengthLocs = 1;
	}
	else if(actualLength == maxLength) cantMaxLengthLocs++;

	if(cantsLocs == cantMaxLengthLocs) mismoLargo = 1;
	else mismoLargo = 0;

}


int main(){
	int n, d, i, answer, answerCantLoc, j, k, unions;
	cin >> n;
	vector< pair< int, int > > viajes;

	for(i = 0; i < n; i++){
		cin >> d;
		viajes.push_back(pair< int, int >(d, i + 1));
	}

	sort(viajes.begin(), viajes.end());

	for(i = 0; i < n + 2; i++){
		finalInter.push_back(0);
		beginInter.push_back(0);
	}

	answer = 0;
	answerCantLoc = 0;
	cantsLocs = 0;
	maxLength = 0;
	for(i = 0; i < n; i++){
		unions = 0;
		j = viajes[i].second;
		k = viajes[i].second;
		if(finalInter[viajes[i].second - 1] != 0){
			j = finalInter[viajes[i].second - 1];
			unions++;
		}
		if(beginInter[viajes[i].second + 1] != 0){
			k = beginInter[viajes[i].second + 1];
			unions++;
		}
		
		unionSet(j, k, unions);
		if(mismoLargo && cantsLocs > answerCantLoc){
			answerCantLoc = cantsLocs;
			answer = viajes[i].first + 1;
		}
	}

	cout << answer << "\n";
	return 0;
}
```