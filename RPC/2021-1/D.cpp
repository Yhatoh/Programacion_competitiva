#include<bits/stdc++.h>

using namespace std;

int main(){
	unsigned long long int t, n, f1, f2, f3, i;
	cin >> t;

	f1 = 1; f2 = 1;
	set< unsigned long long > c;
	c.insert(f1); c.insert(f2);
	for(i = 2; i < 10000; i++){
		f3 = (f1 + f2) %  2147483647;
		f2 = f3;
		f1 = f2;
		c.insert(f3);
	}

	while(t--){
		cin >> n;
		if(c.count(n)) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}