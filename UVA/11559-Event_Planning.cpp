#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int n,b,h,w,p,a,i,si,menor,y;
	while(cin >> n >> b >> h >> w){
		y = 0;
		menor = b+1;
		while(y < h){
			si = 0;
			cin >> p;
			for(i = 0; i < w; i++){
				cin >> a;
				if(a >= n){
					si = 1;
				}
			}
			if(menor > n*p && si == 1) menor = n*p; 
			y++;
		}
		if(menor < b+1) cout << menor << "\n";
		else cout << "stay home" << "\n";
	}
	return 0;
}