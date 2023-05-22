#include<bits/stdc++.h>

using namespace std;

int howManyOnes(int a){
	int count = 0;
	while(a > 0){
		if(a % 2){
			count++;
		}
		a /= 2;
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;

		int even, odd;
		even = odd = 0;
		
		int i;
		for(i = 0; i < n; i++){
			int a;
			cin >> a;
			if(howManyOnes(a) % 2){
				odd++;
			} else {
				even++;
			}
		}

		for(i = 0; i < q; i++){
			int p;
			cin >> p;
			int ansEven = even;
			int ansOdd = odd;
			if(howManyOnes(p) % 2){
				ansOdd = even;
				ansEven = odd;
			}
			cout << ansEven << " " << ansOdd << "\n";
		}
	}
	return 0;
}