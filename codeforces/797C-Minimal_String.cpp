#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	char a, mini, posMini;
	int i, j, encontre;
	string s;
	stack< char > t;
	vector< char > u;
 
	cin >> s;
 
    posMini = -1;
	for(i = 0; i < s.length() - 1; i++){
		t.push(s.at(i));
		if(posMini < i + 1){
            mini = 'z';
			for(j = s.length() - 1; j > i; j--){
				if(mini >= s.at(j)){
					mini = s.at(j);
					posMini = j;
				}
				if(mini == 'a') break;
			}
		}
		while(!t.empty()){
			if(t.top() <= mini){
				u.push_back(t.top());
				t.pop();
			}
			else break;
		}
	}
	for(i = 0; i < u.size(); i++){
		cout << u[i];
	}
	cout << s.at(s.length() - 1);
	while(!t.empty()){
		cout << t.top();
		t.pop();
	}
	cout << "\n";
	return 0;
}