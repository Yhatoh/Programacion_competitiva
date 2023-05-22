#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	srand (1);
	int S;
	double dicesThrow, total, totalOfTotal;
	cin >> S;

	totalOfTotal = 0;
	for(int i = 0; i < 10; i++){
		total = 0;
		for(int j = 0; j < 10000; j++){
			dicesThrow = 0;
			int S2 = S;
			while(S2 > 1){
				dicesThrow++;
				S2 = rand() % S2 + 1;
			}
			total += dicesThrow;
		}
		totalOfTotal += total / 10000.0;
	}

	cout << (int)round(totalOfTotal / 10.0);
	return 0;
}