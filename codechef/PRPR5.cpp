#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;

bool valid(vector< ll > positions, ll dist, ll t){
	ll cantTraps = 1;
	ll prev = positions[0];
	ll n = positions.size();
	for(ll i = 0; i < n; i++){
		if(n - i + 1 < t - cantTraps){
			return 0;
		}
		if(positions[i] - prev >= dist){
			cantTraps++;
			prev = positions[i];
			if(cantTraps == t)
				return 1;
		}

	}
	return 0;
}

int main(){
	ll n, t, i, low, high, mid, ans;

	cin >> n >> t;

	vector< ll > positions(n);
	for(i = 0; i < n; i++)
		cin >> positions[i];

	sort(positions.begin(), positions.end());

	low = 0;
	high = positions[n - 1];
	ans = 0;
	while(low <= high){
		
		mid = (high + low) / 2;
		if(valid(positions, mid, t)){
			low = mid + 1;
			ans = mid;
		} else {
			high = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}