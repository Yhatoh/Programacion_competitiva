#include<bits/stdc++.h>

using namespace std;

int puentes=0;
vector<int> cantp(2000, 0);
vector<int> dfs_parent(2000, -1);
vector<int> dfs_num(2000, -1);
vector<int> dfs_low(2000, 0);
int contadorDfs = 0;
vector<vector<int>> beer(2000);


void dfs(int u){
	dfs_low[u] = dfs_num[u] = contadorDfs++;
	for(int j = 0; j < beer[u].size(); j++){
		int v = beer[u][j];
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
			dfs(v);
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int n,p,i,x,y;
	cin >> n >> p;
	i = 0;
	while(i < p){
		cin >> x >> y;
		beer[x-1].push_back(y-1);
		i++;
	}
	for(i = 0; i < n; i++){
		if(dfs_num[i] == -1) dfs(i);
	}

	cout << puentes << "\n";
	return 0;
}