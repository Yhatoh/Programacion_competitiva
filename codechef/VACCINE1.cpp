#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	
	int d1, v1, d2, v2, p, i, total;
	cin >> d1 >> v1 >> d2 >> v2 >> p;
	i = 0;
	total = 0;
	while(1){
		if(i >= d1) total += v1;
		
		if(i >= d2) total += v2;
		
		if(total >= p) break;

		i++;
	}
	cout << i << "\n";
	return 0;
}