#include<bits/stdc++.h>

using namespace std;
int main(){
	int b, r, i, max, whereMax, h, v, c;
	cin >> b >> r;
	vector< int > base(b + 1, 0);

	while(r--){
		cin >> h >> v >> c;
		max = -1,
		whereMax = -1;
		for(i = c; i < c + h; i++){
			if(max < base[i]){
				max = base[i];
				whereMax = i;
			}
		}

		for(i = c; i < c + h; i++){
			base[i] = max + v;
		}
	}

	sort(base.begin(), base.end());
	cout << base[b] << "\n";
	return 0;
}