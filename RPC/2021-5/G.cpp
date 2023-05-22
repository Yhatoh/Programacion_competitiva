#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long quant1 = 0;
	long long quant12 = 0;
	long long result = 0;
	for(int i = 0; i < n; i++){
		int rate;
		cin >> rate;
		if(rate == 1){
			quant1 = (quant1 + 1) % 1000000007;
		} else if(rate == 2){
			quant12 = (quant12 * 2 + quant1) % 1000000007;
		} else {
			result = (result + quant12) % 1000000007;
		}
	}
	cout << result << "\n";
	return 0;
}