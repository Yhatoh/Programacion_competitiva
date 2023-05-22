#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector< long long > v(n);
		long long sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		cout << abs(sum) << "\n";
	}
	return 0;
}
