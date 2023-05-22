#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, w;
	cin >> n >> w;
	vector< int > d(n + 1), c(n + 1), u(n + 1), answer(n + 1);

	c[0] = answer[0] = w;
	for(int i = 1; i <= n; i++){
		cin >> d[i] >> c[i] >> u[i];
	}

	int out = w;
	for(int i = 1; i <= n; i++){
		answer[i] = c[i] - u[i] + max(answer[d[i]] - c[i], 0);
		if(answer[i] < out)
			out = answer[i];
	}

	cout << out << "\n";
	return 0;
}