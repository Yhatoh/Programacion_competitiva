#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, n, i, j, cant;
	cin >> t;
	while(t--){
		cin >> n;
		cant = 0;
		vector<int> a(n);
		for(i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int num_0 = 0;
		int num_1 = 0;
		int num_2 = 0;
		int num_3 = 0;
		int num_3_2 = 0;
		int cant_3_2 = 0;
		int num_ant = -1;
		for(i = 0; i < n; i++){
			if(a[i] == 0) num_0++;
			else if(a[i] == 1) num_1++;
			else if(a[i] == 2) num_2++;
			else if(num_ant != a[i]){ num_3++; num_ant = a[i]; cant_3_2 = 1;}
			else{ num_3++; num_3_2 = num_3_2+num_3_2*cant_3_2; cant_3_2++;}
		}
		cant = (num_0-1)*(num_0)/2+(num_1-1)*(num_1)/2+(num_2-1)*(num_2)/2+num_3*num_1;
		cant += num_3_2;
		cout << cant << "\n";
	}
	return 0;
}

// 12 13 14 23 24 34 
// 12 13 23