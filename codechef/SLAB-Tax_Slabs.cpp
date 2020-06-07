#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);

	int T, income, toSubstract;
	cin >> T;
	while(T--) {
		cin >> income;
		toSubstract = 0;

		if(income > 250000) {
			if(income > 500000) {
				toSubstract = toSubstract + (500000 - 250000) * 0.05;
				if(income > 750000) {
					toSubstract = toSubstract + (750000 - 500000) * 0.1;
					if(income > 1000000) {
						toSubstract = toSubstract + (1000000 - 750000) * 0.15;
						if(income > 1250000) {
							toSubstract = toSubstract + (1250000 - 1000000) * 0.2;
							if(income > 1500000) {
								toSubstract = toSubstract + (1500000 - 1250000) * 0.25;
								toSubstract = toSubstract + (income - 1500000) * 0.3;
							}
							else {
								toSubstract = toSubstract + (income - 1250000) * 0.25;
							}
						}
						else {
							toSubstract = toSubstract + (income - 1000000) * 0.2;
						}
					}
					else {
						toSubstract = toSubstract + (income - 750000) * 0.15;
					}
				}
				else {
					toSubstract = toSubstract + (income - 500000) * 0.1;
				}
			}
			else {
				toSubstract = toSubstract + (income - 250000) * 0.05;
			}
		}

		cout << income - toSubstract << "\n";
	}

	return 0;
}