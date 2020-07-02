#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000000000000000

int main(){
	int t, n, k, i;
	long long cant9, x, prefix, fPrefix, minX, T, pow10, d, sum;
	cin >> t;
	while(t--){
		cin >> n >> k;

		minX = MAX;
		pow10 = 1;
		for(cant9 = 0; cant9 < 17; cant9++){
			pow10 = pow10 * 10;
			for(d = 0; d < 10; d++){
				if(d + k > 9) T = 10 - d;
				else T = k + 1;
				sum = 0;
				for(i = 0; i <= k; i++){
					sum += (d + i) % 10;
				}
				fPrefix = n - cant9 * 9 * T - (k + 1 - T) - sum;

				if(fPrefix >= 0 && fPrefix % (k + 1) == 0){
					fPrefix /= (k + 1);

					if(fPrefix < 8) prefix = fPrefix;
					else{
						fPrefix -= 8;
						prefix = fPrefix % 9;
						fPrefix -= fPrefix % 9;

						while(fPrefix > 0){
							prefix *= 10;
							if(fPrefix < 9){ 
								prefix += fPrefix;
								fPrefix = 0;
							}
							else{ 
								prefix += 9;
								fPrefix -= 9;
							}
						}

						prefix = prefix * 10 + 8;
					}
					x = pow10 * prefix + pow10 - 10 + d;
					if(minX > x) minX = x;
				}
			}
		}

		if(minX == MAX) cout << -1 << "\n";
		else cout << minX << "\n";
	}
	return 0;
}