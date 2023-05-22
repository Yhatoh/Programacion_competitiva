#include <bits/stdc++.h>

using namespace std;

int encription(char c){
	if('A' <= c && c <= 'Z'){
		return c - 'A';
	} else if('0' <= c && c <= '9') {
		return c - '0' + 'Z' - 'A' + 1;
	} else {
		return 36;
	}
}

char desencription(int a){
	if(0 <= a && a <= 25){
		return a + 'A';
	} else if(26 <= a && a <= 35) {
		return a - 26 + '0';
	} else {
		return ' ';
	}
}

int main() {
	int n;
	cin >> n;
	vector< vector< unsigned int > > matrix(n);

	int i, j, k;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			int a;
			cin >> a;
			matrix[i].push_back(a);
		}
	}

	string line;
	getline(cin, line);
	getline(cin, line);
	
	int quantVec = ceil((float) line.size() / (float) n);

	for(i = 0; i < quantVec; i++){
		vector< unsigned int > vec(n, 36);
		for(j = 0; j < n; j++){
			if(j + i * n < line.length()){
				vec[j] = encription(line[j + i * n]);
			}
		}
		/*
		for(auto i : vec){
			cout << i << " ";
		}cout << "\n";
		*/

		for(k = 0; k < n; k++){
			int sum = 0;
			for(j = 0; j < n; j++){
				sum += matrix[k][j] * vec[j];
			}

			cout << desencription(sum % 37);
		}
	}
	cout << "\n";

	/*
	for(char c : line){
		cout << encription(c) << " ";
	}
	cout << "\n";
	*/
	return 0;
}