#include<bits/stdc++.h>

using namespace std;


int main(){
	int n;
	cin >> n;
	vector< long long > distanc(n);
	long long total_distance = 0;
	for(int i = 0; i < n; i++){
		long long value;
		cin >> value;
		total_distance += value;
		if(i == 0){
			distanc[i] = value;
		} else {
			distanc[i] = value + distanc[i - 1];
		}
	}

	int j = 0;
	long long curr = 0;
	int booli = 0;
	for(int i = 0; i < n; i++){
		for(; j < n - 1 && 2 * (distanc[j] - curr) < total_distance; j++){}
		if(j < n - 1 && 2 * (distanc[j] - curr) == total_distance){
			booli++;
			if(booli > 1) break;
		}
		curr = distanc[i];
	}

	if(booli > 1) cout << "Y\n";
	else cout << "N\n";


	return 0;
}