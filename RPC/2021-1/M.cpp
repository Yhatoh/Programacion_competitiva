#include<bits/stdc++.h>

using namespace std;

unsigned long long pow_mod(unsigned long long x, unsigned long long n, unsigned long long m){
	unsigned long long y = 1;
	while(n > 0){
		if(n % 2)
			y = (y * x) % m;
		n = n / 2;
		x = (x * x) % m;
	}
	return y;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(5);
	int t;
	unsigned long long m = 2147483647;
	cin >> t;

	unsigned long long six = pow_mod(6, m - 2, m);
	while(t--){
		unsigned long long n;
		unsigned long long a, b, c;
		cin >> n;
		a = n;
		b = n + 1;
		c = n + 2;
		if (a % 2 == 0) {
			a /= 2;
		} else if(b % 2 == 0) {
			b /= 2;
		} else {
			c /= 2;
		}

		if (a % 3 == 0) {
			a /= 3;
		} else if(b % 3 == 0) {
			b /= 3;
		} else {
			c /= 3;
		}
		cout << ((((a % m) * (b % m)) % m) * (c % m)) % m << "\n";
	}
	return 0;
}