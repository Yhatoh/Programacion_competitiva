#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		int booli = 1;
		int n = s.length();
		if(n % 2 == 0){
			int open, close;
			for(int i = 0; i < s.length(); i++){
				if(s[i] == '(') open = i;
				else if(s[i] == ')') close = i;
			}

			if(open == n - 1) booli = 0;
			if(close == 0) booli = 0;
		} else {
			booli = 0;
		}

		if(booli) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}