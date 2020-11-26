#include<bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int n, i, j, total, low, mid, high;
	long long k;
	cin >> n >> k;
	vector< long long > numbers(n);

	for(i = 0; i < n; i++)
		cin >> numbers[i];

	sort(numbers.begin(), numbers.end());

	total = 0;
	for(i = 0; i < n; i++){
		low = 0;
		high = n - 1;
		while(low <= high){
			mid = (high + low) / 2;
			if(numbers[mid] < numbers[i] + k)
				low = mid + 1;
			else
				high = mid - 1;
		}
		total += n - low;
	}

	cout << total << "\n";
	return 0;
}