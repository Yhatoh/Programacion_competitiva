#include<bits/stdc++.h>

using namespace std;

int pares[10000000][2];

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, n, q, i, m, p, odd, even, ah, j;
	
	cin >> t;
	while(t--){
		for(i = 0; i < 10000000; i++){
			pares[i][0] = -1;
			pares[i][1] = -1;	
		}
		cin >> n >> q;
		vector<int> number(n);
		


		for(i = 0; i < n; i++){
			cin >> number[i];
		}

		while(q--){
			odd = 0;
			even = 0;
			cin >> p;
			if(pares[p][0] == -1){
				for(i = 0; i < n; i++){
					ah = 0;
					m = p ^ number[i];
					for(j = 0; m > 0; j++){
						if(m % 2 == 1) ah++;
						m = m / 2;
					}
					if(ah % 2 == 0) even++;
					else odd++;
				}
				pares[p][0] = even;
				pares[p][1] = odd;
				cout << even << " " << odd << "\n";
			}
			else cout << pares[p][0] << " " << pares[p][1] << "\n";
			
		}

	}
	return 0;
}