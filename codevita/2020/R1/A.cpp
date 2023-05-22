#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);

	int m, n, k;
	cin >> m >> n;

	vector< vector < int > > matrix(m);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			int a;
			cin >> a;
			matrix[i].push_back(a);
		}
	}

	cin >> k;
	set< int > nums;
	for(int i = 0; i < k; i++){
		int a;
		cin >> a;
		nums.insert(a);
	}

	int x = sqrt(k);

	int booli = 0;
	for(int i = 0; i < m - x + 1; i++){
		for(int j = 0; j < n - x + 1; j++){
			int cantFinds = 0;
			for(int k = 0; k < x; k++){
				for(int l = 0; l < x; l++){
					if(nums.find(matrix[i + k][j + l]) != nums.end()){
						cantFinds++;
					} else {
						break;
					}
				}
			}
			if(cantFinds == k) booli = 1;
		}
		if(booli) break;
	}

	if(booli) cout << "Possible";
	else cout << "Not Possible";

	return 0;
}