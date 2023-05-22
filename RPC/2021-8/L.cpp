#include<bits/stdc++.h>
using namespace std;
 
typedef pair<long long, long long> parLarg;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie();
	int n, L, Q;
	cin >> n >> L >> Q;
	vector<vector<pair< int, int>>> graph(n);
	long long a, b, w, u, d, l, v, w2;
	for(int i = 0; i < L; i++){
		cin >> a >> b >> w;
		graph[a-1].push_back(parLarg(b-1,w));
		graph[b-1].push_back(parLarg(a-1,w));			
	}
 
 	while(Q--){
 		int letraI, letraJ;
 		cin >> letraI >> letraJ;
 		letraI--;
 		letraJ--;
		vector<int> camino(n, -1);
		vector<long long> encuantollego(n, 1000000000000); 
		encuantollego[letraI] = 0;
		priority_queue<parLarg, vector<parLarg>, greater<parLarg>> pQueue;
		pQueue.push(parLarg(0,letraI));
		while(!pQueue.empty()){
			w2 = pQueue.top().first;
			u = pQueue.top().second;
	 
			pQueue.pop();
	 
			if(w2 > encuantollego[u]) continue;
			//if(u == n-1) break;
	 
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
		if(encuantollego[letraJ] == 1000000000000) cout << -1 << "\n";
		else{
			cout << encuantollego[letraJ] << "\n";
		}
	}
	return 0;
}