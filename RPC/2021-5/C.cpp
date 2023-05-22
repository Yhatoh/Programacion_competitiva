#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector< int > locations(n);

	for(int i = 0; i < n; i++)
		cin >> locations[i];
	
	int minEnergy = 1000000000;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			int actualEnergy = 0;
			for(int k = 0; k < n; k++){
				actualEnergy += (abs(locations[k] - locations[j]) < abs(locations[k] - locations[i]) ? (locations[k] - locations[j]) * (locations[k] - locations[j]) : (locations[k] - locations[i]) * (locations[k] - locations[i]));
			}

			if(actualEnergy < minEnergy)
				minEnergy = actualEnergy;
		}
	}

	cout << minEnergy << "\n";
	return 0;
}