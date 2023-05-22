#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template< class T >
void print(vector< T > &vec) {
	uint64_t i;
	for(i = 0; i < vec.size() - 1; i++) {
		cout << vec[i] << " ";
	}
	cout << vec[i] << "\n";
}

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
		vector< ll > vec(n + 1, 0);
		vector< ll > acum_sum(n + 1, 0);
		for(int i = 1; i <= n; i++) {
			cin >> vec[i];
			acum_sum[i] = acum_sum[i - 1] + vec[i];
		}
		//cout << "------------\n";
		//print<ll>(vec);
		//print<ll>(acum_sum);
		ll ans = 0;
		int first_i = n + 1;
		for(int i = 1; i <= n; i++) {
			if(vec[i] == 0) { first_i = i; break; }
			if(acum_sum[i] == 0) ans++;
		}

		ll max_freq = 0;
		map< ll, ll > freq;
		for(int i = first_i; i <= n; i++) {
			if(vec[i] == 0) { 
				ans += max_freq;
				freq.clear();
				max_freq = 0;
			}
			freq[acum_sum[i]] += 1;
			max_freq = max(max_freq, freq[acum_sum[i]]);
		}
		ans += max_freq;
		cout << ans << "\n";
	}
	return 0;
}
