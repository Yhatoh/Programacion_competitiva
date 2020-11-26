#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, s, t, sAnt, tAnt, winner, maxLead;
	maxLead = 0;
	cin >> n;
	tAnt = sAnt = 0;
	while(n--){
		cin >> s >> t;
		s += sAnt;
		t += tAnt;
		if(s > t && maxLead < s - t){
			maxLead = s - t;
			winner = 1;
		} else if(maxLead < t - s){
			maxLead = t - s;
			winner = 2;
		}
		tAnt = t;
		sAnt = s;
	}
	cout << winner << " " << maxLead << "\n";
	return 0;
}
