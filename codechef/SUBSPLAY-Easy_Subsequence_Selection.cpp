#include<bits/stdc++.h>

using namespace std;

int p = 31;
int m = 1000000000+9;

vector<long long> potencias(100000,-1);


long long  compute_hash(string &s,int k, int j){
	long long hash_value = 0;
	potencias[0] = 1;
	int i;
	for(i = k; i < j+1; i++){
		if(potencias[i] == -1){ 
			potencias[i] = potencias[i-1]*p;
			hash_value = (hash_value + (s[i]-'a'+1)*potencias[i-k])%m;
		}
		else{
			hash_value = (hash_value + (s[i]-'a'+1)*potencias[i-k])%m;
		}
	}
	return hash_value;
}

int main(){

	int t,n,i,j,k,b;
	long long value;
	string s;
	cin >> t;
	while(t--){
		vector<bool> table_hash(m);
		cin >> n >> s;
		k = n-1;
		b = 0;
		while(k > 0){
			i = 0;
			j = k-1;
			while(j < n){
				value = compute_hash(s,i,j);
				if(table_hash[value] == 0) table_hash[value] = 1;
				else{
					b = 1;
					break;
				}
				i++;j++;
			}
			if(b == 1) break;
			k--;
		}
		cout << k << "\n";
	}
	return 0;
}