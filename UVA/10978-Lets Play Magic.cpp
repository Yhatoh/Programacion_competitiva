#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int n, i,j,pos;
	string carta, a;
	cin >> n;
	while(n != 0){
		vector<string> cartas(n);
		for(i = 0; i < n; i++) cartas[i] = " ";
		i = 0;
		pos = n-1;
		while(i < n){
			cin >> carta >> a;
			j = 0;
			while(j < a.length()){
				pos = (pos+1)%n;
				if(cartas[pos] == " "){
					j++;
				}
			}
			cartas[pos] = carta;
			i++;
		}
		for(i = 0; i < n-1; i++) cout << cartas[i] << " ";
		cout << cartas[n-1] << "\n";
		cin >> n;
	}
	return 0;
}