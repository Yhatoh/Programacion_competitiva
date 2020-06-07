#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, d, i, cancion, duration;

	cin >> n >> d;

	duration = d;
	for(i = 0; i < n; i++){
		cin >> cancion;
		duration -= cancion;
	}

	duration -= 10 * (n - 1);
	
	if(duration < 0) cout << -1 << "\n";
	else{
		cout << (n - 1) * 2 + duration / 5 << "\n";
	}


	return 0;
}