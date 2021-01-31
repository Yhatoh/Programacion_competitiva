#include<bits/stdc++.h>

using namespace std;

int main(){
	string a;
	unsigned long long int b;
	cin >> a >> b;
	while(b != 0){
		if(b % 4 == 0){
			cout << a << "\n";
		} else if(b % 4 == 1){
			cout << a << "i\n";
		} else if(b % 4 == 2){
			if(a[0] != '-'){
				cout << "-";
				cout << a << "\n";
			} else {
				cout << a.substr(1, a.length() - 1) << "\n";
			}
		} else{
			if(a[0] != '-'){
				cout << "-";
				cout << a << "i\n";
			} else {
				cout << a.substr(1, a.length() - 1) << "i\n";
			}
		}
		cin >> a >> b;
	}
	return 0;
}