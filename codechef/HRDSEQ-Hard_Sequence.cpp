#include<bits/stdc++.h>

using namespace std;

int buscarpos(vector<int> &seq, int x, int pos){
	int i;
	for(i = pos-1; i >= 0; i--){
		if(seq[i] == x) return i;
	}
	return -1;
}

int main(){
	vector<int> seq(128);
	int x,otrax;
	seq[0] = 0;
	seq[1] = 0;
	int pos = 1;
	int i = 2;
	x = 0;

	while(i < 128){
		otrax = buscarpos(seq,x,pos);
		if(otrax == -1) seq[i] = 0;
		else seq[i] = pos-otrax;

		x = seq[i];
		pos++;
		i++;
	}
	//cout << "[";
	//for(i = 0; i < 127; i++){
	//	cout << seq[i] << ",";
	//}
	//cout << seq[127] << "]\n";

	int t,n;
	cin >> t;
	i = 0;
	int cont;
	while(i < t){
		cin >> n;
		cont = 1;
		otrax = seq[n-1];
		for(x = n-2; x >= 0; x--){
			if(seq[x] == otrax) cont++;
		}
		cout << cont << "\n";
		i++;
	}
	return 0;
}