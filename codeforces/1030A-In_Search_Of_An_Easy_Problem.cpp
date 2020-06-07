#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int n, x;

	cin >> n;
	while(n--){
		cin >> x;
		if(x == 1) break;
	}

	cout << (x == 1 ? "HARD" : "EASY") << "\n";
	return 0;
}