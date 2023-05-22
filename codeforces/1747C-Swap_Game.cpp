#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int first = 0;
		int mini = 1e9 + 7;
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if(!i) first = a;
			mini = min(mini, a);
		}
		if(first == mini) cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}
