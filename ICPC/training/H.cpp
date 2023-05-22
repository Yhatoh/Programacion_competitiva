#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100010
string T, P;
int b[MAX_N], n, m;

void kmpPreprocess(){
	int i = 0, j = -1; b[0] = -1;
	while(i < m){
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

void kmpSearch(){
	int counting = 0;
	vector< int > answers;
	int i = 0, j = 0;
	while(i < n){
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if(j == m){
			counting++;
			answers.push_back(i - j);
			j = b[j];
		}
	}

	if(counting){
		cout << counting << "\n";
		for(i = 0; i < answers.size() - 1; i++){
			cout << answers[i] + 1 << " ";
		}
		cout << answers[i] + 1 << "\n";
	} else {
		cout << "Not Found\n";
	}
}

int main(){
	int t;
	cin >> t;

	while(t--){
		cin >> T >> P;
		n = T.length(); m = P.length();
		kmpPreprocess();
		kmpSearch();
	}
}