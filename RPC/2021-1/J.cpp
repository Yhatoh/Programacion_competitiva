#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(5);
	int t;
	cin >> t;
	while(t--){
		unsigned long long n, result, aux;
		cin >> n;
		result = 2 * n;
		aux = n * n;
		result += 3 * aux;
		result += aux * n;

		cout << (result / 6) << "\n";
	}
	return 0;
}