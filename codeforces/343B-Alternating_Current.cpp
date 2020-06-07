#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int i;
	cin >> s;

	stack< char > pilita;

	pilita.push('f');
	for(i = 0; i < s.length(); i++){
		if(pilita.top() == s.at(i)) pilita.pop();
		else pilita.push(s.at(i));
	}
	cout << (pilita.size() == 1 ? "YES" : "NO") << "\n";
	return 0;
}