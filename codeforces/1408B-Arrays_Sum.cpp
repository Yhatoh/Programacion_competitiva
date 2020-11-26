#include<bits/stdc++.h>

using namespace std;

int main(){
	int t, n, k, cantNoZero, num, numAnt;

	cin >> t;
	while(t--){
		cantNoZero = 0;
		cin >> n >> k;
		if(k == 1){
			cin >> numAnt;
			for(int i = 1; i < n; i++){
				cin >> num;
				if(numAnt != num){
					numAnt = -2;
				}
			}
			if(numAnt == -2) cout << "-1\n";
			else cout << "1\n";
		}
		else{
			cin >> numAnt;
			for(int i = 1; i < n; i++){
				cin >> num;
				if(num != numAnt) cantNoZero++;
				numAnt = num;
			}
			if((int) ceil((double) cantNoZero / (double) (k - 1)) == 0) cout << "1\n";
			else cout << (int) ceil((double) cantNoZero / (double) (k - 1)) << "\n";
		}
	}

	return 0;
}