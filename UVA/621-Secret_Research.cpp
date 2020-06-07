#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	string res;
	int n,i;
	i = 0;
	cin >> n;
	cin >> res;
	while(i < n){
		if(res.compare("1") == 0 || res.compare("4") == 0 || res.compare("78") == 0) cout << "+\n";
		else if(res[res.length()-1] == '5' && res[res.length()-2] == '3') cout << "-\n";
		else if(res[0] == '9' && res[res.length()-1] == '4') cout << "*\n";
		else if(res[0] == '1' && res[1] == '9' && res[2] == '0') cout << "?\n";
		cin >> res;
		i++;
	}
	return 0;
}