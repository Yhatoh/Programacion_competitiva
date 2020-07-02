## 1373E - Sum of digits
### Explicación

Por cada caso nos entregan un n y un k, nos piden encontrar el x menor de forma que:

f(x) + f(x + 1) + f(x + 2) . . . + f(x + k) = n

Primero hay que darse cuenta de lo importante, que f(x + 1) tiene 2 situaciones muy sencillas:

* Caso 1: si el último dígito de x no es 9, entonces f(x + 1) = f(x) + 1
* Caso 2: si el último dígito de x es 9, entonces no podemos aplicar lo anterior puesto que sumarle 9, provocará un efecto en cadena de transformar 9 en 0 hasta que se encuentre con un dígito distinto de 9 y hace se le sumará uno no más.

Gracias a estos dos casos se puede escribir el x de la siguiente forma:

x = (prefijo)(999...99)(d), donde d <= 9, prefijo es un numero > 1 y entre prefijo y d hay una cantidad C de nueves.

Con este x re escrito, podemos generalizar los casos anteriores para cualquier i:

* Caso 1: si d + i <= 9, f(x + i) = f(prefijo) + 9 * C + d + i
* Caso 2: si d + i > 9, f(x + i) = f(prefijo + 1) + (d + i) % 10

Con estos casos, entonces f(x) + f(x + 1) + f(x + 2) + . . . + f(x + k) = n se puede escribir con la siguiente forma:

(sum (d + i) % 10, i from 0 to k) + 9 * C * CantTipo1 + f(prefijo) * CantTipo1 + f(prefijo + 1) * (k + 1 - T) = n

Donde CantTipo1 = min(10 - d, k + 1), puesto que si la distancia entre d y 10 es menor que la cantidad de número consecutivos a sumar sus digitos, la cantidad de número siguiendo el caso 1 serían k + 1.

Ahora despejemos lo anterior:

f(prefijo) * CantTipo1 + f(prefijo + 1) * (k + 1 - CantTipo1) = n - (sum (d + i) % 10, i from 0 to k) - 9 * C * CantTipo1

Ahora como nosotros estamos contruyendo el número en base a la cantidad de 9 entre prefijo y el número d, entonces prefijo jamás tendrá como último dígito un nuevo, por lo que:

f(prefijo + 1) = f(prefijo) + 1

Entonces, la formula anterior queda como

f(prefijo) * (k + 1) = n - (sum (d + i) % 10, i from 0 to k) - 9 * C * CantTipo1 - (k + 1 - CantTipo1)

Entonces, si es que lo que esta en la derecha no es negativo y es divisible por k + 1, existe un prefijo debido a que existe un f(prefijo). Por lo que, solo nos queda determinar que prefijo es el que da como resultado el valor de la derecha dividido en k + 1.

Pra ello, realizaremos el siguiente algoritmo:

```Cpp
if(fPrefix < 8) prefix = fPrefix;
else{
	fPrefix -= 8;
	prefix = fPrefix % 9;
	fPrefix -= fPrefix % 9;

	while(fPrefix > 0){
		prefix *= 10;
		if(fPrefix < 9){ 
			prefix += fPrefix;
			fPrefix = 0;
		}
		else{ 
			prefix += 9;
			fPrefix -= 9;
		}
	}

	prefix = prefix * 10 + 8;
}
```

Finalmente, el x = prefijo * 10^CantTipo1 + 10^CantTipo1 - 10 + d. Y así guardaremos el menor x que podriamos encontrar.

Para ejecutar el código, veremos la cantidad máxima de 9 que puede tener un número, donde como nos dicen que n <= 150, la cantidad de nueves máxima es 17.

### Código propuesto

```Cpp
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000000000000000

int main(){
	int t, n, k, i;
	long long cant9, x, prefix, fPrefix, minX, T, pow10, d, sum;
	cin >> t;
	while(t--){
		cin >> n >> k;

		minX = MAX;
		pow10 = 1;
		for(cant9 = 0; cant9 < 17; cant9++){
			pow10 = pow10 * 10;
			for(d = 0; d < 10; d++){
				if(d + k > 9) T = 10 - d;
				else T = k + 1;
				sum = 0;
				for(i = 0; i <= k; i++){
					sum += (d + i) % 10;
				}
				fPrefix = n - cant9 * 9 * T - (k + 1 - T) - sum;

				if(fPrefix >= 0 && fPrefix % (k + 1) == 0){
					fPrefix /= (k + 1);

					if(fPrefix < 8) prefix = fPrefix;
					else{
						fPrefix -= 8;
						prefix = fPrefix % 9;
						fPrefix -= fPrefix % 9;

						while(fPrefix > 0){
							prefix *= 10;
							if(fPrefix < 9){ 
								prefix += fPrefix;
								fPrefix = 0;
							}
							else{ 
								prefix += 9;
								fPrefix -= 9;
							}
						}

						prefix = prefix * 10 + 8;
					}
					x = pow10 * prefix + pow10 - 10 + d;
					if(minX > x) minX = x;
				}
			}
		}

		if(minX == MAX) cout << -1 << "\n";
		else cout << minX << "\n";
	}
	return 0;
}
```