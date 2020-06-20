## 27E - Number With The Given Amount of Divisors

### Explicación

Por el enunciado nos dicen que el n maximo será 1000, un número sabemos que se contruye como una cantidad de números primos elevados a una potencia determinada. Y gracias a esto podemos saber la cantidad de divisores es (e1 + 1) \* (e2 + 1) \* ... \* (ek + 1), donde e1 es el expontente del primer primo, e2 el segundo expontente del segundo primo y así. 

Y gracias a esa multiplicación se puede determinar que solo necesitamos 10 numeros primeros para resolver este problema puesto que si e1 = e2 = ... = ek = 1, la multiplicación anterior equivale a 1024, que es mayor a 1000. Y con este dato podemos realizar una técnica de busqueda completa.

Donde en esta busqueda completa lo que vamos a hacer es:

* Inicialización: cantidad divisores = 1 (si mismo), numero = 1, primo actual = 2

* Proceso:
 	1. Si cantidad divisores = n -> Ganamos :D
 	2. Si no, significa que debemos agregar el primo actual, intentando por toda potencia posibles mientras la cantidad de divisores * (e + 1) sea menor o igual a n
 		* numero * primo actual ** i, si cantidad divisores * (i + 1) <= n.
 		* Entonces llamamos recursivamente a la función, con cantidad divisiroes = cantidad divisores * (i + 1), primo actual = siguiente primo en la lista, numero = numero * primo actual ** i.
 	3. Luego eventualmente comenzará a retornar y empezamos a comparar los retornos, quedandonos con el más chico.

Complejidad:

* Busqueda completa: O(n^2)

### Código propuesto

```Cpp
#include<bits/stdc++.h>
using namespace std;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

long long backtracking(int cantDiv, int currPrime, long long number, int n){
	if(cantDiv == n) return number;
	long long i;
	long long minNumber, option;
	minNumber = 1e18;

	for(i = 1; cantDiv * (i + 1) <= n; i++){
		number = number * primes[currPrime];
		if(number > minNumber) break;
		
		option =  backtracking(cantDiv * (i + 1), currPrime + 1, number, n);
		if(minNumber > option) 
			minNumber = option;

	}

	return minNumber;
}

int main(){
	
	int n, cantDiv, currPrime, i;
	long long number;

	cantDiv = number = 1;
	currPrime = 0;

	cin >> n;

	cout << backtracking(cantDiv, currPrime, number, n) << "\n";
	return 0;
}
```