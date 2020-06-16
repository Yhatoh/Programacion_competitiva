#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, i;
	string input;
	cin >> t;
	while(t--){
		cin >> input;
		for(i = 0; i < input.length() - 1; i += 2){
			cout << input.at(i);
		}
		cout << input.at(input.length() - 1) << "\n";
		
	}
	return 0;
}