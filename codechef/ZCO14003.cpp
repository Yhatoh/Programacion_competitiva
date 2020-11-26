#include<bits/stdc++.h>
using namespace std;


int main(){
	long long n, i, maxRev, maxPrice;

	cin >> n;
	vector< long long > customer(n);
	for(i = 0; i < n; i++){
		cin >> customer[i];
	}
	sort(customer.begin(), customer.end());

	maxRev = customer[n - 1];
	for(i = n - 2; i >= 0; i--){
		if(maxRev <  customer[i] * (n - i))
			maxRev = customer[i] * (n - i);
	}
	cout << maxRev << "\n";
	return 0;
}