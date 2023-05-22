#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007
typedef long long ll;

ll power(ll num, ll p, ll modu){
	ll ret = 1;
	num = num % modu;

	if(num == 0) return 0;

	while(p > 0){
		if(p % 2 == 1)
			ret = (ret * num) % modu;

		p /= 2;
		num = (num * num) % modu;
	}

	return ret;
}

int main(){
	ll t, n;
	cin >> t;
	while(t--){
		cin >> n;
		
		ll ans = power(2, n - 1, mod);
		cout << ans << "\n";
	} 
	return 0;
}