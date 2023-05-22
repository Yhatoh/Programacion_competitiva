#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector< long long > numbers(n);
	for(int i = 0; i < n; i++){
		cin >> numbers[i];
	}

	long long sum, flag;
	flag = false;
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = 0; j < n; j++){
			sum += (j != i ? numbers[j] : 0);
		}
		if(sum == numbers[i]){
			flag = true;
			break;
		}
	}
	if(flag) cout << sum << "\n";
	else cout << "BAD\n";
	return 0;
}