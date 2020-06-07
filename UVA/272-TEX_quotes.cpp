#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	//` '
	char c;
	int yaviuno = 0;
	while(cin >> noskipws >> c){
		if(c == '"' && yaviuno == 0){
			cout << '`' << '`';
			yaviuno = 1;
		}
		else if(c == '"' && yaviuno == 1){
			cout << "'" << "'";
			yaviuno = 0;
		}
		else cout << c;
	}
	return 0;
}