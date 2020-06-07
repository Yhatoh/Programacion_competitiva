#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(2);
	int n,i,j,k,chars,lineas;
	double peso,precio;
	char car;
	string linea;
	cin >> n;
	i = 0;
	std::map<char,double>::iterator it;
	while(i < n){
		precio = 0.0;
		cin >> chars;
		map<char,double> asd;
		j = 0;
		while(j < chars){
			cin >> car >> peso;
			peso = peso/100.0;
			asd.insert(pair<char,double>(car,peso));
			j++;
		}
		cin >> lineas;
		getline(cin,linea);
		j = 0;
		while(j < lineas){
			linea = "";
			getline(cin,linea);
			for(k = 0; k < linea.length(); k++){
				it = asd.find(linea[k]);
				if(it != asd.end()){
					precio = it->second+precio;
				}
			}
			j++;
		}
		cout << precio << "$\n";
		i++;
	}
	return 0;
}