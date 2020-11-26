#include<bits/stdc++.h>
using namespace std;

typedef pair< long long, long long > ii;
typedef vector< ii > vii;

long long mini = 1000000;

long long calc_dist(ii &c1, ii &c2){
	return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

void back_tracking(vector< vii > &grid, long long k, long long i, long long dist, ii &coord){
	long long j;

	if(i == k + 1){
		if(dist < mini) mini = dist;
		return;
	}

	for(j = 0; j < grid[i].size(); j++){
		if(i == 1){
			back_tracking(grid, k, i + 1, dist, grid[i][j]);
		}
		else if(dist + calc_dist(grid[i][j], coord) < mini){
			back_tracking(grid, k, i + 1, dist + calc_dist(grid[i][j], coord), grid[i][j]);
		}
	}
}


//f(n) = min(dist(coord(n), coord(i)) +f(n - 1)
int main(){
	long long n, k, i, j, num;
	cin >> n >> k;

	vector< vii > grid(k + 1);

	set< int > con;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cin >> num;
			con.insert(num);
			grid[num].push_back(ii(i, j));
		}
	}


	if(con.size() == k){
		ii coord = ii(0,0);
		back_tracking(grid, k, 1, 0, coord);
		cout << mini << "\n";
	} else {
		cout << -1 << "\n";
	}
	return 0;
}