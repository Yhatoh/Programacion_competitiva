#include<bits/stdc++.h>
using namespace std;
 
typedef pair<long long, long long> parLarg;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie();
	int n, m, size;
	cin >> n;
	vector<vector<parLarg>> graph(n);
	cin >> m;
	long long a, b, w, u, d, l, v, w2;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> w;
		graph[a-1].push_back(parLarg(b-1, 2 * w));
		graph[b-1].push_back(parLarg(a-1, 2 * w));			
	}
	vector<int> visitado(n, 0);
	vector<long long> encuantollego(n);
	priority_queue<parLarg> pQueue;

	for(int i = 0; i < n; i++){
		cin >> encuantollego[i];
		pQueue.push(parLarg(-encuantollego[i], i));
	}
	while(!pQueue.empty()){
		size = pQueue.size();
		while((size--) != 0){
			w2 = -pQueue.top().first;
			u = pQueue.top().second;
			pQueue.pop();
	 		if(visitado[u]) continue;
	 		visitado[u] = 1;
			for(int i = 0; i < graph[u].size(); i++){
				v = graph[u][i].first;
				l = graph[u][i].second;
	 
				if(w2 + l < encuantollego[v]){
					encuantollego[v] = w2 + l;
					pQueue.push(parLarg(-(w2 + l), v));
				}
			}
		}
	}
	for(int i = 0; i < n - 1; i++) cout << encuantollego[i] << " ";
	cout << encuantollego[n - 1] << "\n";
	return 0;
}