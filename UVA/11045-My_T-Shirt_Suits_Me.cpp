#include<bits/stdc++.h>
using namespace std;

#define MAX_V 200
#define INF 1000000000
typedef vector<int> vi;

int res[MAX_V][MAX_V], mf, f, s, t;
vi p;


void augment(int v, int minEdge){
	if(v == s){
		f = minEdge;
		return;
	}
	else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int code(string s){
	if (s.compare("XS") == 0) return 6;
	else if (s.compare("S") == 0) return 5;
	else if (s.compare("M") == 0) return 4;
	else if (s.compare("L") == 0) return 3;
	else if (s.compare("XL") == 0) return 2;
	else return 1;
}

int main(){
	int m, n, testCase;
	string talla1, talla2;
	cin >> testCase;

	while (testCase--) {
		cin >> n >> m;
		memset(res, 0, sizeof res);

		//De s a cada talla
		for (int i = 1; i <= 6; i++) res[0][i] = n / 6;
		//De persona i a t
		for (int i = 7; i < 7 + m; i++) res[i][7 + m] = 1;
		//De 2 talla hacia persona i
		for (int i = 7; i < 7 + m; i++) {
			cin >> talla1 >> talla2;
			res[code(talla1)][i] = 1;
			res[code(talla2)][i] = 1;
		}

		s = 0;
		t = 7 + m;

		mf = 0;
		while (1) {
			f = 0;
			vi dist(MAX_V, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 0; v < MAX_V; v++)
					if (res[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u] + 1, q.push(v), p[v] = u;
			}
			augment(t, INF);
			if (f == 0)
				break;
			mf += f;
		}

		if (m == mf) cout << "YES\n";
		else cout << "NO\n";
	}

	
	return 0;
}