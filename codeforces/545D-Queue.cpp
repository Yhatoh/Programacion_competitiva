#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n, timeAcum, notAngry, i;
	
	cin >> n;
	vector< long long > times(n);
	for(i = 0; i < n; i++)
		cin >> times[i];
	
	sort(times.begin(), times.end());
	
	/*
	for(i = 0; i < n; i++)
		cout << times[i] << "\n";
	*/
	timeAcum = 0;
	notAngry = 0;
	for(i = 0; i < n; i++){
		if(timeAcum <= times[i]) {
			notAngry++;
			timeAcum += times[i];
		}
		
	}
	cout << notAngry << "\n";
	return 0;
}