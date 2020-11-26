#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	int t, n, i, smallI, small, time;
	cin >> t;

	while(t--){
		cin >> n;
		vector< int > dishes(n);
		vector< int > burney;

		for(i = 0; i < n; i++) cin >> dishes[i];
		if(n == 1){
			cout << dishes[0] << "\n";
		} else {
			sort(dishes.begin(), dishes.end());

			time = 0;
			i = n - 1;
			while(i >= 0){
				if(burney.size() == 0 && i == 0){
					burney.push_back(dishes[i]);
					break;
				} else if(burney.size() == 0){
					burney.push_back(dishes[i]);
					burney.push_back(dishes[i - 1]);
					i -= 2 ;
				} else {
					burney.push_back(dishes[i]);
					i -= 1;
				}

				smallI = (burney[0] >= burney[1] ? 1 : 0);
				small = burney[smallI];

				time += small;

				burney[0] -= small;
				burney[1] -= small;

				if(burney[1] == 0){
					burney.pop_back();
					if(burney[0] == 0) burney.pop_back();
				} else if(burney[0] == 0){
					burney[0] = burney[1];
					burney.pop_back();
				}
			}

			if(burney.size() != 0) time += burney[0];

			cout << time << "\n";
		}
	}
	return 0;
}