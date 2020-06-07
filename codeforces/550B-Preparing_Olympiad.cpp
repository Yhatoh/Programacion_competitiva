#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, l, r, x, i, j, min, max, difTotal, cant;

	vector<int> problems(n);

	cin >> n >> l >> r >> x;
	for(i = 0; i < n; i++)
		cin >> problems[i];

	cant = 0;
	for(i = 0; i < (1 << n); i++){
		min = 1000000000;
		max = 1;
		difTotal = 0;
		for(j = 0; j < n; j++){
			if((i & (1 << j)) != 0){
				if(problems[j] > max) max = problems[j];
				if(problems[j] < min) min = problems[j];
				difTotal += problems[j];
			}
		}
		if(difTotal >= l && difTotal <= r && max - min >= x) cant++;
	}

	cout << cant << "\n";


	return 0;
}