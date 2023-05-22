#include<bits/stdc++.h>
using namespace std;

int main(){
	long long two = 2;
	long long three = 3;
	long long n, i;

	long long ants_D = 1;
	long long ants_ABC = 0;
	cin >> n;
	for(i = 1; i <= n; i++){
		long long aux = ants_D;
		ants_D = (ants_ABC * three) % 1000000007;
		ants_ABC = (ants_ABC * 2 + aux) % 1000000007;
	}

	cout << ants_D << "\n";
}