#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, n, k, i, j, sign, sum, count;
	cin >> t;
	while(t--){
		cin >> n >> k;
		vector< int > nums(n + 1, 0);
		if(n % 2){
			for(i = 1; i <= n; i++) 
				nums[i] = (i % 2 ? 1 : -1) * i;
		} else {
			for(i = 1; i <= n; i++) 
				nums[i] = (i % 2 ? -1 : 1) * i;
		}
		sum = 0;
		count = ceil((double)n / 2);
		for(i = 1; i <= n; i++){
			sum += nums[i];
			if(sum > 0){
				sign = -2;
				if(count < k){
					sign = -1;
				} else if(count > k){
					sign = 1;
				}
				if(sign != -2){
					for(j = n; j >= 1; j--){
						if(sign * nums[j] > 0){
							nums[j] = -1 * nums[j];
							count += -1 * sign;
							if(count == k) break;
						}
					}
				}
			}
		}
		
		
		for(i = 1; i < n; i++) cout << nums[i] << " ";
		cout << nums[i] << "\n";
	}
	return 0;
}
