#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n, m, t;

	cin >> t; 
	while(t--){
		cin >> n >> m;
		vector< long long > mods(n + 1, 1);
		long long i, j, res, ans;
		ans = 0;
		for(i = 2; i <= n; i++){	
			res = m % i;
			ans += mods[res];
			for(j = res; j <= n; j += i)
				mods[j]++;
		}

		cout << ans << "\n";
	}
	return 0;
}