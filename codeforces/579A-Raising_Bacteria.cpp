#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	long long x, i, j;
	cin >> x;

	j = 0;
	while(x > 0){
		if(x % 2 == 1) j++;
		x = x / 2;
	}
	cout << j << "\n";
	return 0;
}