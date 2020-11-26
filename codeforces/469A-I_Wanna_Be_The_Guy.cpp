#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int n, p, l;

	cin >> n;
	vector< int > level(n + 1, 0);

	cin >> p;
	while(p--){
		cin >> l;
		level[l] = 1;
	}

	cin >> p;
	while(p--){
		cin >> l;
		level[l] = 1;
	}

	for(l = 1; l <= n; l++){
		if(!level[l]) break;
	}

	if(l != n + 1) cout << "Oh, my keyboard!\n";
	else cout << "I become the guy.\n";
	return 0;
}