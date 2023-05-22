#include<bits/stdc++.h>

using namespace std;


int main(){
	long long n, t;
	cin >> n >> t;
	vector< long long > times(n);

	for(long long i = 0; i < n; i++){
		cin >> times[i];
	}

	long long acum = 0;
	long long begin = 0;
	long long maxi = 0;
	for(long long i = 0; i < n; i++){
		acum += times[i];
		//cout << acum << " " << begin << " " << i << "\n";
		if(acum > t){
			if(maxi < i - begin){
				maxi = i - begin;
			}
			while(acum > t){
				acum -= times[begin];
				begin++;
			}
		} else {
			if(i == n - 1){
				if(maxi < i - begin + 1){
					maxi = i - begin + 1;
				}
			}
		}
	}

	cout << maxi << "\n";

	

	return 0;
}