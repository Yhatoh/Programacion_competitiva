#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector< int > glasses(n);
	int prom = 0;
	for(int i = 0; i < n; i++){
		cin >> glasses[i];
		prom += glasses[i];
	}

	prom /= n;

	for(int i = 0; i < n; i++){
		glasses -= prom;
	}

	vector< int > positions;
	for(int i = 0; i < n; i++){
		if(glasses[i] > 0)
			positions.push_back(i);
	}

	int total_cost = 0;
	for(int i = 0; i < positions.size(); i++){
		int moved = 1;
		for(int j = positions[i] + 1; j < positions[i]; j = (j + 1) % n){
			total_cost += moved * 
		}
	}
	return 0;
}