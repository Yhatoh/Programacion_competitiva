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