#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		vector< int > r;
		vector< int > b;
		int n, m;
		cin >> n;
		for (int i = 0; i < n; i++){
			int a;
			cin >> a;
			r.push_back(a);
		}
		cin >> m;
		for (int i = 0; i < m; i++){
			int a;
			cin >> a;
			b.push_back(a);
		}

		int max_r, sum_r, max_b, sum_b;
		max_r = sum_r = max_b = sum_b = 0;
		for(int i = 0; i < n; i++){
			sum_r += r[i];
			if(sum_r > max_r) max_r = sum_r;
		}

		for(int i = 0; i < m; i++){
			sum_b += b[i];
			if(sum_b > max_b) max_b = sum_b;
		}
		cout << (max_b + max_r > 0 ? max_b + max_r : 0) << "\n";
	}
	return 0;
}