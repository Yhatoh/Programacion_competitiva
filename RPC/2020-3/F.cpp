#include<bits/stdc++.h>

using namespace std;

int main(){

	int t, p, i, j, k;

	cin >> t >> p;

	vector< double > fuerzas(t);
	vector< double > prob(p);
	for(i = 0; i < t - 1; i++) cin >> fuerzas[i];
	for(i = 0; i < p; i++) cin >> prob[i];

	char x;
	vector< vector < char > > teams(t);

	for(i = 0; i < t; i++){
		for(j = 0; j < p; j++){
			cin >> x;
			teams[i].push_back(x);
		}
	}

	int cantProbSolv = 0;
	int cantProbSolv2, cantProbNotSolv, boola;
	double probAcum = 1.0;
	double probAcumTeam, probAcumXD, probMulAcumXD;
	for(i = 0; i < p; i++){
		if(teams[t - 1][i] == 'X') cantProbSolv++;
	}

	if(cantProbSolv == p) cout << 1.0 << "\n";
	else{
		boola = 0;
		for(i = t - 2; i >= 0; i--){
			probAcumTeam = 1.0;
			cantProbSolv2 = 0;
			cantProbNotSolv = 0;
			for(j = 0; j < p; j++){
				if(teams[i][j] == 'X') cantProbSolv2++;
				else if(teams[i][j] == '-') cantProbNotSolv++;
			}

			if(cantProbSolv2 > cantProbSolv){boola = 1; break;}
			else if(cantProbSolv2 + cantProbNotSolv < p){

				
				int cantProb = p - cantProbSolv2 - cantProbNotSolv;

				probAcumXD = 0.0;
				int number = pow(2, cantProb) - 1;
		
				for(j = number; j >= 0; --j){
					int contador = 0;
					probMulAcumXD = 1;
					int clonaJ = j;
					if(j == 0){
						while(contador < p){
							if(teams[i][contador] == '?'){
								probMulAcumXD *= (1 - prob[contador]);
							}
							contador++;
						}
					}
					else{
						while(clonaJ > 0){
							if(teams[i][contador] == '?'){	
								int sere1 = clonaJ % 2;
								clonaJ = clonaJ / 2;
								if(sere1){
									probMulAcumXD *= prob[contador];
								}
								else{
									probMulAcumXD *= (1 - prob[contador]);
								}
							}
							contador++;
						}
					}
					probAcumXD += probMulAcumXD;
					cout << "XD " << probAcumXD << "\n";
				}
				probAcumXD *= pow(fuerzas[i], p); 
				probAcumTeam *= probAcumXD;
				cout << "XD2 " << probAcumTeam << "\n";
			} 			
			probAcum *= probAcumTeam;
		}
		if(boola) cout << 0.0 << "\n";
		else{
			cout << probAcum << "\n";
		}
	}
	return 0;
}