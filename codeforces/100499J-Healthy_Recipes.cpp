#include<bits/stdc++.h>

using namespace std;


int main(){
	int t, n, m, k, i, j, count1, count2, a;
	cin >> t;
	while(t--){
		cin >> n >> m >> k;

		long long mochila[103][10005];
		vector< long long > recetas;
		long long count0 = 1;
		
		for(i = 0; i < n; i++){
			cin >> a;
			if(a == 0){ 
				if(count0 <= 100) count0 *= 2;
			}
			else recetas.push_back(a);
		}

		if(recetas.size() > 0){
			for(i = 0; i < recetas.size(); i++) mochila[i][0] = 1;
			for(i = 0; i <= m; i++){
				if(recetas[0] == i){
					mochila[0][i] = 1;
				} else mochila[0][i] = 0;
			}
			mochila[0][0] = 1;
	    
			for(i = 1; i < recetas.size(); i++){
				for(j = 1; j <= m; j++){
					count1 = 0;
					if(recetas[i] <= j){
						count1 = mochila[i - 1][j - recetas[i]];
					}
					count2 = mochila[i - 1][j];
					mochila[i][j] = min(count1 + count2, k);
				}
			}
			if(mochila[recetas.size() - 1][m] * count0 >= k)
				cout << "ENOUGH\n";
			else
				cout << mochila[recetas.size() - 1][m] * count0 << "\n";

		} else {
			if(m != 0) cout << 0 << "\n";
			else if(count0 >= k) cout << "ENOUGH\n";
			else cout << count0 << "\n";
		}
	}
	return 0;	
}