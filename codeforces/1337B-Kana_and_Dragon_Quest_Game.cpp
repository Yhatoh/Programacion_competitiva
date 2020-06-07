#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(7);
	int t, x, n, m, i, muerto;
	cin >> t;
	while(t--){
		muerto = 0;
		cin >> x >> n >> m;
		for(i = 0; i < n; i++){
			if(x / 2 >= 10)
				x = x / 2 + 10;
			else break;
		}
		for(i = 0; i < m; i++){
			x -= 10;
			if(x <= 0){
				muerto = 1;
				break;
			}
		}

		if(muerto) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}