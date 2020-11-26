#include<bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	long long n, i, total;
	cin >> n;
	vector< long long > teams(n);

	for(i = 0; i < n; i++)
		cin >> teams[i];

	sort(teams.begin(), teams.end());

	total = 0;
	for(i = n - 1; i >= 0; i--){
		total += i * teams[i] - (n - 1 - i) * teams[i];
	}
	

	cout << total << "\n";
	return 0;
}