#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector< ll > vll;

bool binarySearch(vll &arr, ll l, ll r, ll x){
    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (arr[m] == x){
            return 1;
        }

        if (arr[m] < x){
            l = m + 1;
        } else{
            r = m - 1;
        }
    }
    return 0;

}

int main(){
	ll n, m, a, c, x0, i;
	cin >> n >> m >> a >> c >> x0;


	vll sequence;
	sequence.push_back((a * x0 + c) % m);

	for(i = 1; i < n; i++){
		sequence.push_back((a * sequence[i - 1] + c) % m);
	}

	ll count = 0;
	for(i = 0; i < n; i++){
		if(binarySearch(sequence, 0, n - 1, sequence[i])){
			count++;
		}
	}

	cout << count << "\n";
	return 0;
}