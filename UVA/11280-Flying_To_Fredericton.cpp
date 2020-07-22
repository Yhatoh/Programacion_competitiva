#include<bits/stdc++.h>

using namespace std;


int main(){
	long long t, n, m, i, j, h, cost, q, stopovers, a, b, u;
	string city1, city2;

	cin >> t;
	h = 1;
	while(t >= h){
		map< string, long long > cities;
		cin >> n;
		vector< vector< pair< long long, long long > > > flights(n);
		
		for(i = 0; i < n; i++){
			cin >> city1;
			cities[city1] = i;
		}

		cin >> m;

		for(i = 0; i < m; i++){
			cin >> city1 >> city2 >> cost;

			flights[cities[city1]].push_back(pair<long long, long long>(cities[city2], cost));
		}

		vector< long long > costs(n, INT_MAX);
		vector< long long > dist(n, INT_MAX);
		dist[0] = 0;

		for(i = 0; i < n - 1; i++){
			for(u = n - 1; u >= 0; u--){
				for(j = 0; j < flights[u].size(); j++){
					a = flights[u][j].first;
					b = flights[u][j].second;
					dist[a] = min(dist[a], dist[u] + b);
				}
			}
			costs[i] = dist[n - 1];
		}

		cout << "Scenario #" << h << "\n";

		cin >> q;
		while(q--){
			cin >> stopovers;
			if(stopovers >= n - 1) stopovers = n - 2;

			if(costs[stopovers] == INT_MAX) cout << "No satisfactory flights\n";
			else cout << "Total cost of flight(s) is $" << costs[stopovers] << "\n";
		}
		if(h < t) cout << "\n";
		h++;
	}
	
	return 0;
}