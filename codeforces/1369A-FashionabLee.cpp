#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << (n % 4 ? "NO" : "YES") << "\n";
	}
	return 0;
}