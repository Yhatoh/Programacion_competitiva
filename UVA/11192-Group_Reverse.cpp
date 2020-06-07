#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int g,min,max,i;
	char aux;
	string linea;
	cin >> g;
	while(g != 0){
		min = 1;
		cin >> linea;
		max = linea.length()/g;
		while(min < linea.length()){
			for(i = 0; i < (max-min)/2+1; i++){
				aux = linea[min-1+i];
				linea[min-1+i] = linea[max-1-i];
				linea[max-1-i] = aux;
			}
			min = min + linea.length()/g;
			max = max + linea.length()/g;
		}
		cout << linea << "\n";
		cin >> g;
	}
	return 0;
}