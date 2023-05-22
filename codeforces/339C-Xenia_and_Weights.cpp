#include <bits/stdc++.h>
using namespace std;

int m;

int get_node(int i, int j, int k){
	  return i*(m + 1)*19 + j*(m + 1) + k;
}

int get_i(int node){
	  return node / ((m + 1)*19);
}

int get_j(int node){
	  return (node % ((m + 1) * 19)) / (m + 1);
}

int get_k(int node){
	  return node % (m + 1);
}

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
	os << "";
	for(uint64_t i = 0; i < vec.size(); i++) {
		os << get_i(vec[i]);
		if(i != vec.size() - 1)
			os << " ";
	}
	os << "\n";
	return os;
}

vector< vector< int > > G(40*40*2000);
vector< int > D(40 * 40 * 2000, 1e6 + 7);
vector< int > parent(40 * 40 * 2000, -1);
void BFS(int a) {
	queue<int> Q;
	D[a] = 0;
	Q.push(a);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int v : G[u]) {
			if(D[v] > D[u] + 1) {
				D[v] = D[u] + 1;
				parent[v] = u;
				Q.push(v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	string A;
	cin >> A;
	cin >> m;
	vector< int > weights;
	for(int i = 1; i < 11; i++) {
		if(A[i - 1] == '1')
			weights.push_back(i);
	}
	// peso actual
	for(int i = 0; i < 11; i++) {
		// balance actual
		for(int j = 0; j <= 10; j++) {
			// step actual
			for(int k = 0; k <= m; k++) {
				int node = get_node(i, j, k);
				if(k > 0) {
					for(int w2 : weights) {
						if(j < w2 && w2 != i) {
							int new_node = get_node(w2, w2 - j, k - 1);
							G[node].push_back(new_node);
						}
					}
				} else {
					G[node].push_back(40*40*2000 - 1);
				}
			}
		}
	}
				
	BFS(get_node(0, 0, m));
	if(parent[40*40*2000 - 1] == -1) cout << "NO\n";
	else {
		vector< int > ans;
		int u = 40*40*2000 - 1;
		while(parent[u] != -1) {
			ans.push_back(parent[u]);
			u = parent[u];
		}
		ans.pop_back();
		reverse(ans.begin(), ans.end());
		cout << "YES\n";
		cout << ans << "\n";		
	}
	return 0;
}
