#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	int n,i= 0,j,k;
	while(i < t){
		cin >> n;
		vector<char> ant(10);
		j = 1;
		for(k = 0; k < 10; k++){
			cin >> ant[k];
		}
		//cout << "[";
		//for(k = 0; k < 9; k++){
		//	cout << ant[k] << ",";
		//}
		//cout << ant[9] << "]\n";

		while(j < n){
			vector<char> act(10);
			for(k = 0; k < 10; k++){
				cin >> act[k];
			}
			//cout << "[";
			//for(k = 0; k < 9; k++){
			//	cout << act[k] << ",";
			//}
			//cout << act[9] << "]\n";

			for(k =0; k < 10; k++){
				if(ant[k] != act[k]){
					ant[k] = '1';
				}
				else ant[k] = '0';
			}

			//cout << "[";
			//for(k = 0; k < 9; k++){
			//	cout << ant[k] << ",";
			//}
			//cout << ant[9] << "]\n";
			j++;
		}
		int cont = 0;
		for(k = 0; k < 10; k++){
			if(ant[k] == '1') cont++;
		}
		cout << cont << "\n";
		i++;
	}
	return 0;
}