#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, i, j, booli;

	cin >> t;

	vector< int > bools(1024);
	while(t--){
		cin >> n;
		for(i = 0; i < 1024; i++) bools[i] = 0;

		vector< int > S(n + 1);

		for(i = 1; i <= n; i++){
			cin >> S[i];
			bools[S[i]] = 1;
		}

		
		for(i = 1; i < 1024; i++){
			booli = 1;
			for(j = 1; j <= n; j++){
				if(bools[S[j] ^ i] == 0){
					booli = 0;
					break;
				}
			}
			if(booli){
				cout << i << "\n";
				break;
			}
		}

		if(booli == 0) cout << -1 << "\n";
	}
	return 0;
}