#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, m, n, i, mins;

	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<int> min(m);
		vector<int> fruit(m);
		vector<int> baskets(n);
		vector<int> prices(n);

		for(i = 0; i < m; i++) {min[i] = 0;fruit[i] = 0;}

		for(i = 0; i < n; i++){ 
			cin >> baskets[i];
			fruit[baskets[i] - 1] = 1;
		}
		for(i = 0; i < n; i++) cin >> prices[i];

		

		for(i = 0; i < n; i++) min[baskets[i] - 1] = min[baskets[i] - 1] + prices[i];

		mins = (fruit[0] == 1 ? min[0] : 10000000);
		for(i = 1; i < m; i++){
			if(min[i] < mins && fruit[i] == 1) mins = min[i];
		}
		cout << mins << "\n";
	}
	return 0;
}