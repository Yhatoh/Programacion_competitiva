#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int T,N,p,s,total,i;
	cin >> T;
	while(T--){
		vector<int> maximos(8,0);
		cin >> N;
		total = 0;
		while(N--){
			cin >> p >> s;
			if(p != 9 && p != 10 && p != 11){
				if(maximos[p-1] < s) maximos[p-1] = s;
			}
		}
		for(i = 0; i < 8; i++) total = total + maximos[i];
		cout << total << "\n";
	}
	return 0;
}