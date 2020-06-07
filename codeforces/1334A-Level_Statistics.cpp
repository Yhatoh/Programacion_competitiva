#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(2);
	int t, n, p, c, pAnt, cAnt, tof;

	cin >> t;
	while(t--){
		cin >> n;
		tof = 1;
		pAnt = -1;
		cAnt = -1;
		while(n--){
			cin >> p >> c;
			if(p < pAnt || c < cAnt){
				tof = 0;
			}
			else{
				if(p < c || p - pAnt < c - cAnt){
					tof = 0;
				}
				pAnt = p;
				cAnt = c;
			}
		}
		if(tof) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}