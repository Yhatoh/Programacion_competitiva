#include<bits/stdc++.h>
using namespace std;

#define MAX_V 100
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

int main(){
	int m, n, testCase, cases, i, k, j, sticker;
	cin >> testCase;

	cases = 0;
	while (testCase > cases++) {
		cin >> n >> m;
		memset(res, 0, sizeof res);

		//Bob
		vi cantStickers(m + 1, 0);
		cin >> k;
		for(j = 0; j < k; j++){
			cin >> sticker; 
			cantStickers[sticker]++;
		}

		for(j = 1; j <= m; j++) res[0][j] = cantStickers[j];
		
		//El resto
		for(i = 1; i < n; i++){
			vi cantStickers(m + 1, 0);
			cin >> k;
			for(j = 0; j < k; j++){
				cin >> sticker; 
				cantStickers[sticker]++;
			}

			for(j = 1; j <= m; j++){
				if(cantStickers[j] == 0) res[j][m + i] = 1;
				if(cantStickers[j] > 1) res[m + i][j] = cantStickers[j] - 1;
			}
		}

		for(i = 1; i <= m; i++) res[i][n + m] = 1;
		
		//res matrix n + m, n + m
		s = 0;
		t = n + m;

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

		cout << "Case #" << cases << ": " << mf << "\n";
	}

	
	return 0;
}