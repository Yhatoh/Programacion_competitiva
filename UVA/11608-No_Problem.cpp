#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int prob,i,j;
	vector<int> creo(12);
	vector<int> necesito(12);
	cin >> prob;
	j = 1;
	while(prob >= 0){
		i = 0;
		cout << "Case " << j << ":\n";
		while(i < 12){
			cin >> creo[i];
			i++;
		}
		i = 0;
		while(i < 12){
			cin >> necesito[i];
			i++;
		}
		i = 0;
		while(i < 12){
			if(prob < necesito[i]) cout << "No problem. :(\n";
			else{
				prob = prob - necesito[i];
				cout << "No problem! :D\n";
			}
			prob = prob +creo[i];
			i++;
		}
		j++;
		cin >> prob;
	}
	return 0;
}