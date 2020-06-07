#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	
	int T, n, goalsA, goalsB, shotsA, shotsB, i;
	string shots;
	cin >> T;
	while(T--) {
		cin >> n >> shots;
		i = shotsA = shotsB = goalsB = goalsA = 0;

		while(i < 2 * n) {
			if(i % 2 == 0){
				shotsA++;
				goalsA += (shots.at(i) == '1' ? 1 : 0);
			}
			else {
				shotsB++;
				goalsB += (shots.at(i) == '1' ? 1 : 0);
			}

			if(goalsA < goalsB) {
				if(n - shotsA < goalsB - goalsA) break;
			}
			else if(goalsA > goalsB) {
				if(n - shotsB < goalsA - goalsB) break;
			}
			i++;
		}
		
		cout << (i == 2 * n ? i : i + 1) << "\n";

	} 

	return 0;
}