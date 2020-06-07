#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	long long n,i,j,max,mul;
	cin >> n;
	int arr[n];
	i = 0;
	while(i < n){
		cin >> arr[i];
		i++;
	}

	i = 0;

	suma_k = 0;
	suma_n = 0;
	max = 0;
	while(i < n){
		
		suma_k = suma_k + arr[i]*arr[i];
		
		suma_n = suma_n - arr[i];
		for(j = i+1; j < n;j++){
			suma_n = suma_n + arr[j];
		}


		mul = suma_n*suma_k;
		if(mul > max){
			max = mul;
		}
		i++;
	}
	cout << max << "\n";
	return 0;
}