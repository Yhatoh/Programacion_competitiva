#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(7);
	int t, x, n, m, i, muerto;
	cin >> t;
	while(t--){
		muerto = 0;
		cin >> x >> n >> m;
    
    while(x > 0 && n > 0 && x - m * 10 > 0) {
      x /= 2;
      x += 10;
      n--;
    }
    if(x <= m * 10) muerto = 1;

		if(muerto) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
