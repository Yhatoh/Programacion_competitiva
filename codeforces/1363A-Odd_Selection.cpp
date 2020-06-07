#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(2);
	int t, n, x, a, cantOdd, cantEven, i;
	cin >> t;
	while(t--){
		cin >> n >> x;
		cantOdd = 0;
		i = 0;
		while(n > i){
			cin >> a;
			if(a % 2) cantOdd++;
			i++;
		}
		cantEven = n - cantOdd;
		if(cantOdd >= x){
			if(x % 2) cout << "Yes\n";
			else{
				if(cantEven >= 1) cout << "Yes\n";
				else cout << "No\n";
			}
		}
		else{
			if(x == n){
				if(cantOdd % 2) cout << "Yes\n";
				else cout << "No\n";
			}
			else{
				if(cantOdd){
					cout << "Yes\n";
				}
				else cout << "No\n";
			}
		}
	}
	return 0;
}