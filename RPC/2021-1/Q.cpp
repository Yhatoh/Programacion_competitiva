#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		stack< int > q;
		int max, min, q;
		max = -1;
		min = 100001;
		cin >> q;
		if(q == 1){
			int pushed;
			cin >> pushed;	
			if(max < pushed) max = pushed;
			if(min > pushed) min = pushed;
			q.push(pushed);
		} else if(q == 2){
			if(!q.empty()) q.pop();
		} else if(q == 3){
			if(q.empty()) cout << "Empty!\n";
			else{
				cout << abs(max - min) << "\n";
			}
		}
	}
	return 0;
}