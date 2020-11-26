#include<bits/stdc++.h>

using namespace std;

int main(){

	long long T, n, k, i, toMult, min, totalIzq;


	cin >> T;
	while(T--){	
		min = 100000000000000;

		cin >> n >> k;
		vector< vector<long long> > cases(n);
		vector< long long > coins(n);

		//Initial Case
		cin >> coins[0];
		totalIzq = coins[0];
		cases[0].push_back(coins[0] % k);
		cases[0].push_back(0);
		cases[0].push_back(0);

		for(i = 1; i < n; i++){
			cin >> coins[i];
			cases[0][2] += (coins[i] % k == 0 ? 0 : k - coins[i] % k);
		}

		toMult = (cases[0][2] - cases[0][0]) / k + ((cases[0][2] - cases[0][0]) % k == 0 ? 0 : 1);
		if(cases[0][0] < cases[0][2]){
			if(totalIzq - cases[0][0] >= toMult * k){
				cases[0][1] = cases[0][0] + toMult * k;
			}
			else cases[0][1] = 10000000000000001;
		}
		else cases[0][1] = cases[0][0];

		min = (cases[0][1] - cases[0][2] < min ? cases[0][1] - cases[0][2] : min);

		//Other cases made from the last case seen
		for(i = 1; i < n; i++){
			cases[i].push_back(cases[i - 1][0] + coins[i] % k);
			cases[i].push_back(0);
			cases[i].push_back(cases[i - 1][2] - (coins[i] % k == 0 ? 0 : k - coins[i] % k));

			totalIzq = totalIzq + coins[i];
			
			if(cases[i][0] < cases[i][2]){
				toMult = (cases[i][2] - cases[i][0]) / k + ((cases[i][2] - cases[i][0]) % k == 0 ? 0 : 1);

				if(totalIzq - cases[i][0] >= toMult * k) cases[i][1] = cases[i][0] + toMult * k;
				else cases[i][1] = 1000000000000000001;
			}
			else cases[i][1] = cases[i][0];

			min = (cases[i][1] - cases[i][2] < min ? cases[i][1] - cases[i][2] : min);
		} 

		cout << min << "\n";

	}
	return 0;
}