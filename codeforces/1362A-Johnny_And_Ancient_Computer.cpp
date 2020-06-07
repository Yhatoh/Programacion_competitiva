#include<bits/stdc++.h>
using namespace std;

long long countShift(long long a){
	long long cont = 0;

	while(a != 1){
		cont++;
		if(a % 8 == 0) a /= 8;
		else if(a % 4 == 0) a /= 4;
		else if(a % 2 == 0) a /= 2;
		else{cont = 0; break;}
	}

	return cont;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(2);

	int t;
	long long a, b, cont;

	cin >> t;
	while(t--){
		cin >> a >> b;
		if(a == b) cout << 0 << "\n";
		else if(a > b){
			if(a % b != 0) cout << -1 << "\n";
			else{
				a = a / b;
				cont = countShift(a);
				if(cont) cout << cont << "\n";
				else cout << -1 << "\n";
			}
		}
		else{
			if(b % a != 0) cout << -1 << "\n";
			else{
				a = b / a;
				cont = countShift(a);
				if(cont) cout << cont << "\n";
				else cout << -1 << "\n";
			}
		}
	}
	return 0;
}