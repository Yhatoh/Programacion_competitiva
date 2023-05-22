#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);


	int t, x, k, n;
	cin >> t;
	while(t--){
		cin >> n >> x >> k;
		if(x % k == 0) {
			cout << "YES\n";
		// x = 3, n + 1 -> 0
		} else if(-1 * (x - (n + 1)) % k == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}