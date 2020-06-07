#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, n, k, i, j, contBreak, max, l;
	cin >> t;
	while(t--){
		cin >> n >> k;
		vector< int > alturas(n + 1);
		for(i = 1; i < n + 1; i++) cin >> alturas[i];

		contBreak = 0;
		
		contBreak = 1;
		for(j = 2; j < 1 + k - 1; j++){
			if(alturas[j] > alturas[j - 1] && alturas[j] > alturas[j + 1]) 
				contBreak++;
		}
		max = contBreak;
		l = 1;
		i = 2;
		while(i + k  - 1 <= n){
			if(alturas[i] > alturas[i - 1] && alturas[i] > alturas[i + 1])
				contBreak--;
			if(alturas[i + k - 2] > alturas[i + k - 1] && alturas[i + k - 2] > alturas[i + k - 3])
				contBreak++;
			if(max < contBreak){
				max = contBreak;
				l = i;
			}
			i++;
		}
		cout << max << " " << l << "\n";
	}
	return 0;
}