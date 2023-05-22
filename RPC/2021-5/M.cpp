#include<bits/stdc++.h>

using namespace std;

int main(){
	string x;
	string y;
	cin >> x;
	cin >> y;

	int quantSX = 0;
	for(int i = 0; i < x.length(); i++){
		if(x[i] == 'S')
			quantSX++;
	}
	int quantSY = 0;
	for(int i = 0; i < y.length(); i++){
		if(y[i] == 'S')
			quantSY++;
	}

	string result = "";

	for(int i = 0; i < quantSY * quantSX; i++)
		result += "S(";
	result += "0";
	for(int i = 0; i < quantSY * quantSX; i++)
		result += ")";

	cout << result << "\n";
	return 0;
}