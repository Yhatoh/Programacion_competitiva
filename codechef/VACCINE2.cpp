#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	
	int t;
	cin >> t;
	while(t--){
		int n, d, i, a, risk, notRisk, cantDays;
		cin >> n >> d;

		risk = 0;
		notRisk = 0;

		for(i = 0; i < n; i++){
			cin >> a;
			if(a <= 9 || a >= 80) risk++;
			else notRisk++;
		}

		cantDays = risk / d + (risk % d > 0 ? 1 : 0);
		cantDays += notRisk / d + (notRisk % d > 0 ? 1 : 0);

		cout << cantDays << "\n";
	}
	return 0;
}