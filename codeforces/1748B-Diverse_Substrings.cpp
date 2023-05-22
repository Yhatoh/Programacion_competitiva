#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	//cout.precision(4);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		for(int i = 0; (uint64_t) i < s.length(); i++) {
			vector< int > v(10, 0);
			int diff = 0;
			int max_freq = 0;
			for(int j = i; (uint64_t) j < s.length() && v[s[j] - '0'] < 10; j++) {
				v[s[j] - '0'] += 1;
				if(v[s[j] - '0'] == 1) diff++;
				max_freq = max(v[s[j] - '0'], max_freq);
				if(max_freq <= diff) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
