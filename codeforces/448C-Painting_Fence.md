## 448C - Painting Fenc
### Explicación

Según como nos explican, lo ideal es siempre que la cantidad de pintadas horizontales debe ser lo más grande posible, por lo que primero sabemos que la cantidad minima de strokes sería el minimo entre todas las alturas. Y también la cantidad máxima de stroke en un segmento [l, r], sería r - l + 1 puesto que sería pintar cada plank verticalmente.

Entonces la idea, será aplicar una función recursiva diviendo el problema en 2 partes. 

Si tenemos un segmento [l, r], tomaremos la menor altura y guardaremos su indice (minI), que sería la cantidad minima de strokes a hacer, luego a cada posición entre l y r le restaremos la altura minima encontra. Luego dividimos el problema en dos segmentos [l, minI - 1] y [minI + 1, r].

Cuando estos dos problemas se hayan resuelto, nos preguntaremos si es que:

* ¿valor [l, minI - 1] + valor [minI + 1, r] + menor altura pillada antes < r - l + 1?

	* Si r - l + 1 es menor, entonces retornamos valor [l, minI - 1] + valor [minI + 1, r] + menor altura pillada antes
	* Si no retornamos r - l + 1

Complejidad:

* O(n^2)

### Código propuesto

```Cpp
#include<bits/stdc++.h>
using namespace std;
#define INF 1000000001;
vector< long long > fence;


long long painting(int l, int r){
	if(l > r) return 0;
	int i, min, minI;
	long long strokes, div1, div2;

	min = INF;
	for(i = l; i < r + 1; i++){
		if(min > fence[i]){
			minI = i;
			min = fence[i];
		}
	}

	strokes = min;
	for(i = l; i < r + 1; i++) fence[i] -= strokes;

	div1 = painting(l, minI - 1);
	div2 = painting(minI + 1, r);

	if(div1 + div2 + strokes < r - l + 1) return div1 + div2 + strokes;
	else return r - l + 1;
}

int main(){
	int n, i, j;
	cin >> n;
	
	for(i = 1; i <= n; i++){
		cin >> j;
		fence.push_back(j);
	}

	cout << painting(0, n - 1) << "\n";
	return 0;
}
```