#include<bits/stdc++.h>
using namespace std;

int trades(vector< string > persons, vector< string > hass, vector< string > wants, int start){
	int trade = 0;
	int n = persons.size();
	int cur = start;
	vector< int > used(n, 0);
	while(1){
		int breakit = 1;
		for(int i = 0; i < n; i++){
			//cout << wants[i] << " " << hass[cur] << "\n";
			if(used[i] == 0 && wants[i] == hass[cur]){
				cur = i;
				trade++;
				breakit = 0;
				used[i] = 1;
				break;
			}
		}
		if(breakit)
			break;
	}
	if(used[start]) return trade;
	return 0;
}

int main(){
	int n;
	cin >> n;
	vector< string > persons(n);
	vector< string > hass(n);
	vector< string > wants(n);

	for(int i = 0; i < n; i++){
		cin >> persons[i] >> hass[i] >> wants[i];
	}

	int maxi = 0;
	int start = 0;

	for(int i = 0; i < n; i++){
		int res = trades(persons, hass, wants, start);
		if(res > maxi){
			maxi = res;
		}
		start++;
	}

	if(maxi)
		cout << maxi << "\n";
	else 
		cout << "No trades possible\n";
	return 0;
}