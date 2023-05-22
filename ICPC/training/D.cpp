#include<bits/stdc++.h>
using namespace std;
 
typedef pair<long long, long long> parLarg;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie();
	int n, m;
	cin >> n;
	vector<vector<pair< int, int>>> graph(n);
	cin >> m;
	long long a, b, w, u, d, l, v, w2;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> w;
		graph[a-1].push_back(parLarg(b-1,w));
		graph[b-1].push_back(parLarg(a-1,w));			
	}
 
	vector<int> camino(n, -1);
	vector<int> caminoFinal;
	vector<long long> encuantollego(n, 1000000000000); 
	encuantollego[0] = 0;
	priority_queue<parLarg, vector<parLarg>, greater<parLarg>> pQueue;
	pQueue.push(parLarg(0,0));
	while(!pQueue.empty()){
		w2 = pQueue.top().first;
		u = pQueue.top().second;
 
		pQueue.pop();
 
		if(w2 > encuantollego[u]) continue;
		if(u == n-1) break;
 
		for(int i = 0; i < graph[u].size(); i++){
			v = graph[u][i].first;
			l = graph[u][i].second;
 
			if(w2 + l < encuantollego[v]){
				camino[v] = u;
				encuantollego[v] = w2+l;
				pQueue.push(parLarg(w2+l,v));
			}
		}
	}
	//imposible llegar
	if(encuantollego[n-1] == 1000000000000) cout << -1 << "\n";
	else{
		for(int i = n - 1; i != -1; i = camino[i]){
			caminoFinal.push_back(i+1);
		}
		for(int i = caminoFinal.size()-1; i >= 0; i--) cout << caminoFinal[i] <<" ";
		cout << "\n";
	}
	return 0;
}