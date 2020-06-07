#include<bits/stdc++.h>

using namespace std;

typedef pair< int, double > pid;
typedef vector< pid > vpid;
typedef vector< vpid > vv;

int main(){
	int n, m, i, j, k;
	double p;
	cin >> n >> m; 
	vv prob(n + 1);
	vector< int > last(n + 1, 0);

	while(m--){
		cin >> i >> j >> p;
		double acum = 0.0;

		if(last[i]){
			double plast;
			for(k = 0; k < prob[i].size(); k++){
				if(prob[i][k].first == last[i]) plast = prob[i][k].second;
				acum += 1 - prob[i][k].second;
			}

			acum = acum + plast * (1 - p);
		}
		else{
			acum = 1 - p;
		}

		for(k = 0; k < prob[j].size(); k++){
			if(prob[j][k].first == i){
				prob[j][k].second = acum;
				break;
			}
		}
		if(k == prob[j].size()) prob[j].push_back(pair<int, double>(i, acum));
		last[j] = i;
		/*
		for(int l = 1; l < prob.size(); l++){
			cout << l << " -> ";
			for(int v = 0; v < prob[l].size(); v++){
				cout << prob[l][v].first << "," << prob[l][v].second << " ";
			}
			cout << "\n";
		}
		*/
	}

	for(int k = 1; k < prob.size(); k++){
		
		if(last[k]){
			for(int l = 0; l < prob[k].size(); l++){
				if(prob[k][l].first == last[k]) cout << prob[k][l].second << "\n";
			}
		}
		else cout << 1 << "\n";

	}
	return 0;
}