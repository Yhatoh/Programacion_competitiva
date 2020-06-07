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
	int n,i,prom,cant,cas;
	cin >> n;
	cas = 1;
	while(n != 0){
		prom = 0;
		cant = 0;
		vector<int> stacks(n);
		for(i = 0; i < n; i++){
			cin >> stacks[i];
			prom = prom + stacks[i];
		}
		prom = prom/n;
		for(i = 0; i < n; i++){
			if(stacks[i]-prom > 0) cant = stacks[i]-prom+cant;
		}
		cout << "Set #" << cas++ << "\n";
		cout << "The minimum number of moves is " << cant << ".\n\n";
		cin >> n;
	}
	return 0;
}