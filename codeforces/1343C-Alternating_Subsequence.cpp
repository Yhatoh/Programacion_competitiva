#include<bits/stdc++.h>

using namespace std;

int main(){
	long long t, n, i, nOp, sumar, aSumar;
	long long original[200002];
	cin >> t;
	while(t--){
		cin >> n;
		for(i = 0; i < n; i++){
			cin >> original[i];
		}
		if(original[0] < 0) nOp = -1;
		else nOp = 1;

		sumar = 0;
		aSumar = original[0];
		for(i = 1; i < n; i++){
			if(aSumar * original[i] >= 0){
				if(aSumar < original[i]) aSumar = original[i];

				if(aSumar < original[i]) aSumar = original[i];

			}
			else{
				if(nOp == 1) nOp = -1;
				else nOp = 1;
				sumar += aSumar;
				aSumar = original[i];
			}
		}
		sumar += aSumar;
		cout << sumar << "\n";

	}
	return 0;
}