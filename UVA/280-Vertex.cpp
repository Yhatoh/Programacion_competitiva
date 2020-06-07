#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector< vi > graph;
#define VISITADO 1
#define NO_VISITADO 0
int visitados[100][100];
int boi = 0;
int dab = -1;

void dfs(int u,graph mapa, int papa){
	if(papa == -1){
		papa = u;
	}
	else{
		visitados[papa][u] = VISITADO;
	}
	for (int j = 0; j < mapa[u].size(); j++){
		int v = mapa[u][j];
		if (visitados[papa][v] == NO_VISITADO){
			dfs(v,mapa, papa);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r;
	cin >> a;
	b = 0;
	while(a != 0){
		graph mapa(100);
		cin >> b;
		while(b != 0){
			cin >> c;
			while(c != 0){
				mapa[b-1].push_back(c-1);
				cin >> c;
			}
			cin >> b;
		}
		cin >> c;
		e = 0;
		for (i = 0; i < a; ++i)
			memset(visitados[i], NO_VISITADO, sizeof(int)*a);
		while(e < c){
			cin >> n;
			dfs(n-1,mapa,-1);
			for(i = 0; i < a; i++){
				if(visitados[n-1][i] == VISITADO){
					boi++;
				}
			}
			cout << a-boi;
			for(i = 0; i < a; i++){
				if(visitados[n-1][i] == NO_VISITADO){
					cout << " " << i+1;
				}
			}
			dab = -1;
			boi = 0;
			cout << "\n";
			e++;
		}
		cin >> a;
	}
	return 0;
}