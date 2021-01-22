#include<bits/stdc++.h>
using namespace std;

#define VISITADO true
#define NO_VISITADO false

vector < vector< int > > adjlist;
vector < bool > visitados;

void dfs(int nodoActual){
    visitados[nodoActual] = VISITADO;

    //adjlist[nodoActual].size() cuantos vecinos tiene el nodo actual
    for(int i = 0; i < adjlist[nodoActual].size(); i++){
        int vecino = adjlist[nodoActual][i];
        if(visitados[vecino] == NO_VISITADO){
            dfs(vecino);
        }
    }

}

int main(){
	int t;
	char line;
	scanf("%d%c", &t, &line);
	scanf("%c", &line);
	while(1){
		if(t == 0){
			break;
		}
		
		t--;

		char masGrande, nodeA, nodeB;
		scanf("%c%c", &masGrande, &line);
		int tamano = masGrande - 'A' + 1;
		adjlist.assign(tamano, vector< int >());
		visitados.assign(tamano, NO_VISITADO);
		while(scanf("%c", &nodeA) != EOF && nodeA != '\n'){
			scanf("%c%c", &nodeB, &line);

			int realA, realB;
			realA = nodeA - 'A';
			realB = nodeB - 'A';
			

			adjlist[realA].push_back(realB);
			adjlist[realB].push_back(realA);
		}

		int componentes = 0;
		for(int i = 0; i < tamano; i++){
			if(visitados[i] == NO_VISITADO){
				dfs(i);
				componentes++;
			}
		}

		printf("%d\n", componentes);
		if(t != 0)
			printf("\n");

		adjlist.clear();
		visitados.clear();
	}
	return 0;
}