#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int n, i;
	string num;
	cin >> n;
	i = 0;
	while(i < n){
		cin >> num;
		if((num[0] == 'o' && num[2] == 'e') || (num[0] == 'o' && num[1] == 'n') || (num[1] == 'n' && num[2] == 'e')) cout << 1 << "\n";
		else if((num[0] == 't' && num[2] == 'o') || (num[0] == 't' && num[1] == 'w') || (num[1] == 'w' && num[2] == 'o')) cout << 2 << "\n";
		else if((num[0] == 't' && num[1] == 'h' && num[2] == 'r' && num[3] == 'e') || (num[4] == 'e' && num[1] == 'h' && num[2] == 'r' && num[3] == 'e') || (num[0] == 't' && num[4] == '3' && num[2] == 'r' && num[3] == 'e') || (num[0] == 't' && num[1] == 'h' && num[4] == 'e' && num[3] == 'e') || (num[0] == 't' && num[1] == 'h' && num[2] == 'r' && num[4] == 'e')) cout << 3 << "\n";
		i++;
	}
	return 0;
}