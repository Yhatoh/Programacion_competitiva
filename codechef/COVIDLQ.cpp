#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);

	int t, n, i, a, j;

	cin >> t;
	while(t--){
		cin >> n;

		vector< int > people(n);
		j = 0;
		for(i = 0; i < n; i++){
			cin >> a;
			if(a == 1)
				people[j++] = i;
		}
		a = 1;
		for(i = 0; i < j - 1; i++){
			if(people[i + 1] - people[i] < 6){
				a = 0;
				break;
			}
		}
		if(a) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}