#include<bits/stdc++.h>

using namespace std;

int esta(vector<int> &coin, int i){
	int j;
	for(j = 0; j < coin.size(); j++){
		if(coin[j] == i) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int m,n,k,p,i,unique,c;
	char sign;
	cin >> m;
	while(m--){
		cin >> n >> k;
		vector<int> coins(n,1);
		while(k--){
			cin >> p;
			vector<int> left(p);
			vector<int> right(p);
			i = 0;
			while(2*p > i){
				if(i < p){
					cin >> left[i];
					left[i]--;
				}
				else {
					cin >> right[i-p];
					right[i-p]--;
				}
				i++;
			}
			cin >> sign;
			if(sign == '='){
				for(i = 0; i < p; i++){
					coins[left[i]] = 0;
					coins[right[i]] = 0;
				}
			}
			else{
				for(i = 0; i < n; i++){
					if(!(esta(right,i) || esta(left,i))){
						coins[i] = 0;
					}
				}
			}
		}
		//for(i = 0; i < n; i++) cout << coins[i] << "\n";
		unique = 0;
		c = -1;
		for(i = 0; i < n; i++){
			if(coins[i] == 1) {unique++; c = i;}
		}
		if(unique == 1) cout << c+1 << "\n";
		else cout << "0\n";
		if(m != 0) cout << "\n";
	}
	return 0;
}