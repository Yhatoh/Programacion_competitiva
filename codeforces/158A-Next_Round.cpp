#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n, k, cont, i, score, scoreK;

	cin >> n >> k;
	cont = 0;
	for(i = 1; i <= n; i++){
		cin >> score;
		if(i == k) scoreK = score;

		if(i <= k && score > 0) cont++;
		else if(i <= k && score <= 0) break;
		else if(score >= scoreK) cont++;
		else break;
	}
	cout << cont << "\n";
	return 0;
}