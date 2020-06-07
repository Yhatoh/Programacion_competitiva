#include<bits/stdc++.h>

using namespace std;

vector< int > finalInter;
vector< int > beginInter;

int maxLength;
int mismoLargo;
int cantsLocs;
int cantMaxLengthLocs;

void unionSet(int i, int j, int rest){
	int actualLength = j - i + 1;
	if(rest > 0) cantsLocs -= rest;

	//A que intervalo pertenece idea DSU
	finalInter[j] = i;
	beginInter[i] = j;
	cantsLocs++;

	if(actualLength > maxLength){
		maxLength = actualLength;
		cantMaxLengthLocs = 1;
	}
	else if(actualLength == maxLength) cantMaxLengthLocs++;

	if(cantsLocs == cantMaxLengthLocs) mismoLargo = 1;
	else mismoLargo = 0;

}


int main(){
	int n, d, i, answer, answerCantLoc, j, k, unions;
	cin >> n;
	vector< pair< int, int > > viajes;

	for(i = 0; i < n; i++){
		cin >> d;
		viajes.push_back(pair< int, int >(d, i + 1));
	}

	sort(viajes.begin(), viajes.end());

	for(i = 0; i < n + 2; i++){
		finalInter.push_back(0);
		beginInter.push_back(0);
	}

	answer = 0;
	answerCantLoc = 0;
	cantsLocs = 0;
	maxLength = 0;
	for(i = 0; i < n; i++){
		unions = 0;
		j = viajes[i].second;
		k = viajes[i].second;
		if(finalInter[viajes[i].second - 1] != 0){
			j = finalInter[viajes[i].second - 1];
			unions++;
		}
		if(beginInter[viajes[i].second + 1] != 0){
			k = beginInter[viajes[i].second + 1];
			unions++;
		}
		
		unionSet(j, k, unions);
		if(mismoLargo && cantsLocs > answerCantLoc){
			answerCantLoc = cantsLocs;
			answer = viajes[i].first + 1;
		}
	}

	cout << answer << "\n";
	return 0;
}