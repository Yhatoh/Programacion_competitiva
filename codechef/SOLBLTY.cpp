#include<bits/stdc++.h>

using namespace std;

int main() {
	int x, a, b, t;

	cin >> t;
	while(t--){
		cin >> x >> a >> b;
		cout << (a + (100 - x) * b) * 10 << "\n"; 
	}
	return 0;
}