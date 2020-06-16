#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, i, a, wEven, wOdd;
	cin >> t;
	while(t--){
		cin >> n;
		wEven = wOdd = 0; 
		for(i = 0; i < n; i++){
			cin >> a;
			if(a % 2 != i % 2 && a % 2) wOdd += 1;
			else if(a % 2 != i % 2) wEven += 1;
		}
		if(wOdd != wEven) cout << -1 << "\n";
		else cout << wEven << "\n";
	}
	return 0;
}