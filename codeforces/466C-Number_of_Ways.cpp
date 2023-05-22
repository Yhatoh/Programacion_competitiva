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
	int n;
	cin >> n;
	vector< ll > nums(n + 1);
	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> nums[i];
		sum += nums[i];
	}

	if(sum % 3 != 0) {
		cout << "0\n";
		return 0;
	}
	
	ll s = sum / 3;
	vector< ll > prefix(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + nums[i];
	}

	vector< ll > suffix(n + 2, 0);
	vector< ll > bina(n + 1, 0);

	for(int i = n; i >= 0; i--) {
		suffix[i] = suffix[i + 1] + nums[i];
		bina[i] = suffix[i] == s;
	}

	vector< ll > sufbina(n + 1, 0);
	sufbina[n] = bina[n];
	for(int i = n - 1; i >= 1; i--) {
		sufbina[i] = sufbina[i + 1] + bina[i];
	}

	ll ans = 0;
	for(int i = 1; i <= n - 2; i++) {
		if(prefix[i] == s) ans += sufbina[i + 2];
	}
	//print<ll>(nums);
	//print<ll>(prefix);
	//print<ll>(bina);
	//print<ll>(sufbina);
	cout << ans << "\n";
	return 0;
}
