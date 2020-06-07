#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, k, k_n, exp;
	cin >> t;
	while(t--){
		cin >> n;
		k = 2;
		exp = 2;
		k_n = 3;
		while(n % k_n != 0){
			exp = exp * 2;
			k_n += exp;
			k++;
		}
		cout << n / k_n << "\n";
	}
	return 0;
}