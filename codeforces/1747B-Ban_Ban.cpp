#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n == 1) {
			cout << "1\n1 2\n";
		} else {
			cout << (n % 2 ? n / 2 + 1 : n / 2) << "\n";
			int len = n * 3;
			int pos = 1;
			int last = n * 3;
			for(int i = 0; i < (n % 2 ? n / 2 + 1 : n / 2); i++) {
				cout << pos << " " << last << "\n";
				pos += 3;
				last -= 3;
			}
		}
	}
	return 0;
}
