#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, n, m, k, cantJok, cantPla, cantMax, iter;
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		if(m == 0) cout << 0 << "\n";
		else if(n / k >= m) cout << m << "\n";
		else{
			cantJok = n / k;
			m = m - cantJok;
			cantPla = k - 1;

			cantMax = 0;
			iter = 0;
			while(m > 0){

				iter++;
				m--;
				if(iter == 1) cantMax++;
				if(iter % cantPla == 0) iter = 0;

			}
			cout << cantJok - cantMax << "\n";
		}
	}
	return 0;
}