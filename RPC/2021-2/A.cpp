#include<bits/stdc++.h>
using namespace std;

typedef vector< pair< double, double > > vpii;

double obtainDistance(vpii &p, vpii &s, int indexP, int indexS){
	double diff1 = (p[indexP].first - s[indexS].first);
	double diff2 = (p[indexP].second - s[indexS].second);
	return diff1 * diff1 + diff2 * diff2;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(6);

	int n, m, p, i, j, k, indexJ, indexO;
	double acum, distance;

	cin >> n >> m >> p;

	vpii judges(n);
	vector< int > usedJ(n, 0);
	vpii repo(m);
	vector< int > usedR(m, 0);
	vpii store(p);
	vector< int > usedP(p, 0);

	for(i = 0; i < n; i++){
		cin >> judges[i].first >> judges[i].second;
	}
	for(i = 0; i < m; i++){
		cin >> repo[i].first >> repo[i].second;
	}
	for(i = 0; i < p; i++){
		cin >> store[i].first >> store[i].second;
	}

	acum = 0;

	for(k = 0; k < n; k++){
		indexJ = 0;
		indexO = 0;
		distance = 1000000000;
		for(i = 0; i < n; i++){
			if(usedJ[i] == 0){
				for(j = 0; j < m; j++){
					if(usedR[j] == 0){
						double thisDistance = obtainDistance(judges, repo, i, j);
						if(distance > thisDistance){
							distance = thisDistance;
							indexO = j;
							indexJ = i;
						}
					}
				}
			}
		}
		usedR[indexO] = 1;
		acum += sqrt(distance);
		usedJ[indexJ] = 1;
	}

	for(i = 0; i < n; i++){
		usedJ[i] = 0;
	}
	for(k = 0; k < n; k++){
		indexJ = 0;
		indexO = 0;
		distance = 1000000000;
		for(i = 0; i < n; i++){
			if(usedJ[i] == 0){
				for(j = 0; j < p; j++){
					if(usedP[j] == 0){
						double thisDistance = obtainDistance(judges, store, i, j);	
						if(distance > thisDistance){
							distance = thisDistance;
							indexO = j;
							indexJ = i;
						}
					}
				}
			}
		}
		usedP[indexO] = 1;
		acum += sqrt(distance);
		usedJ[indexJ] = 1;
	}

	cout << acum << "\n";
	return 0;
}