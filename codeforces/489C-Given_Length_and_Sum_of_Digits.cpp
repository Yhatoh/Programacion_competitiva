#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, s;
	cin >> m >> s;
	string mini = "";
	string maxi = "";

	if(m * 9 < s || (s == 0 && m > 1)) {
		cout << -1 << " " << -1 << "\n";
		return 0;
	}
	int sum = s;
	for(int i = 0; i < m; i++) {
		for(int d = 9; d >= 0; d--) {
			if(i > 0 || d > 0 || (m == 1 && d == 0)) {
				if((m - i - 1) * 9 >= sum - d && sum - d >= 0) {
					sum -= d;
					maxi += '0' + d;
					break;
				}
			}
		}
	}

	sum = s;
	for(int i = 0; i < m; i++) {
		for(int d = 0; d < 10; d++) {
			if(i > 0 || d > 0 || (m == 1 && d == 0)) {
				if((m - i - 1) * 9 >= sum - d && sum - d >= 0) {
					sum -= d;
					mini += '0' + d;
					break;
				}
			}
		}
	}
	
	cout << mini << " " << maxi << "\n";
	return 0;
}
