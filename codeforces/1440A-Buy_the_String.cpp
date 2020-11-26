#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, n, c0, c1, h, i, total;
	char bin;
	cin >> t;
	while(t--){
		cin >> n >> c0 >> c1 >> h;

		c0 = (h + c1 < c0 ? h + c1 : c0);
		c1 = (h + c0 < c1 ? h + c0 : c1);

		total = 0;
		for(i = 0; i < n; i++){
			cin >> bin;
			if(bin == '0') total += c0;
			else total += c1;
		}
		cout << total << "\n";
	}
	return 0;
}