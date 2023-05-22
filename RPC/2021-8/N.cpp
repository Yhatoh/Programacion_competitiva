#include<bits/stdc++.h>
using namespace std;

int main() {
	vector< long long > total(6, 0);

	int p;
	cin >> p;

	while(p--){
		vector< long long > prof(6, 0);
		int c;
		cin >> c;

		while(c--){
			char nota;
			cin >> nota;
			prof[nota - 'A']++;
		}

		for(int i = 0; i < 6; i++){
			total[i] += prof[i];
			cout << (char)(i + 'A') << ":" << prof[i] << (i < 5 ? " " : "\n");
		}
	} 
	cout << "TOTAL: ";
	for(int i = 0; i < 6; i++){
		cout << (char)(i + 'A') << ":" << total[i] << (i < 5 ? " " : "\n");
	}
}