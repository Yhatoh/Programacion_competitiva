#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, n, k, i, mid, pos;
	long long total;
	cin >> t;
	while(t--){
		cin >> n >> k;
		vector< long long > a(n * k);
		for(i = 0; i < n * k; i++)
			cin >> a[i];
		total = 0;
		mid = n / 2;
		pos = n * k - 1;
		while(k){
			pos -= mid;
			total += a[pos];
			pos--;
			k--;
		}
		cout << total << "\n";
	}
	return 0;
}