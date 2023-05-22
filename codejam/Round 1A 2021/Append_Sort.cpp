#include <bits/stdc++.h>
using namespace std;

int main() {
	long long potencias[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
	long long t, n, k;
	cin >> t;
	k = 0;
	while(t > k){
		cin >> n;
		long long numberIminusOne, numberI, cantAppend;
		cin >> numberIminusOne;
		cantAppend = 0;
		for(long long i = 1; i < n; i++){
			cin >> numberI;
			long long lenNumberI = (long long)log10((double)numberI) + 1;
			long long lenNumberIminusOne = (long long)log10((double)numberIminusOne) + 1;
			if(numberI <= numberIminusOne) {
				long long howMuchAppend = 0;
				if(lenNumberIminusOne == lenNumberI) {
					cantAppend += 1;
					numberI *= 10;
					numberIminusOne = numberI;
					continue;
				}

				long long add = lenNumberIminusOne - lenNumberI;
				numberI *= potencias[add];
				cantAppend += add;
				howMuchAppend += add;

				long long auxI = numberI;
				long long auxIminusOne = numberIminusOne;
				long long j = 0;
				while(auxI <= auxIminusOne && potencias[howMuchAppend] > j){
					auxI += 1;
					j += 1;
				}

				if(auxI <= auxIminusOne){
					numberI *= 10;
					cantAppend += 1;
				} else if(potencias[howMuchAppend] == j){
					cantAppend += 1;
					numberI *= 10;
				} else{
					numberI = auxI;
				}
			}
			numberIminusOne = numberI;
		}
		cout << "Case #" << ++k << ": " << cantAppend << "\n";
	}
	return 0;
}