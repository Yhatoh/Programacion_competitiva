#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int n,p1,p2,p3,i;
	cin >> n;
	i = 0;
	while(i < n){
		cin >> p1 >> p2 >> p3;
		if(p1 <= p2 && p1 <= p3){
			if(p2 <= p3) cout << "Case " << i+1 << ": " << p2 << "\n";
			else cout << "Case " << i+1 << ": " << p3 << "\n";
		}
		else if(p2 <= p1 && p2 <= p3){
			if(p1 <= p3) cout << "Case " << i+1 << ": " << p1 << "\n";
			else cout << "Case " << i+1 << ": " << p3 << "\n";
		}
		else if(p3 <= p2 && p3 <= p1){
			if(p2 <= p1) cout << "Case " << i+1 << ": " << p2 << "\n";
			else cout << "Case " << i+1 << ": " << p1 << "\n";
		}
		i++;
	}
	return 0;
}