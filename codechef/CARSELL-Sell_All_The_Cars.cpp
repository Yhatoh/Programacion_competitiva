#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);

	long long t, n, i, year, total;
	cin >> t;
	while(t--){
		cin >> n;
		vector< long long > prices(n);
		for(i = 0; i < n; i++) cin >> prices[i];

		sort(prices.begin(), prices.end());

		year = 0;
		total = 0;

		while(prices.size() > 0){
			if(prices[prices.size() - 1] - year > 0)
				total = (total + prices[prices.size() - 1] - year) % 1000000007;
			else break;

			prices.erase(prices.begin() + prices.size() - 1);
			year++;
		} 
		cout << total << "\n";

	}
	return 0;
}