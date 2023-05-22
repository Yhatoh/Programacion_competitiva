#include<bits/stdc++.h>
using namespace std;

int main(){
	vector< long long > penta(816498);
	long long iterations = 0;
	long long e12 = (long long) 1000000000000;
	while(1){
		penta[iterations] = iterations*(3 * iterations - 1) / 2;
		if(iterations*(3 * iterations - 1) / 2 > e12){ break;}
		iterations+=1;
	}
	//999998168776
	//1000000618265
	int t; 
	cin >> t;
	while(t--){
		long long c;
		cin >> c;

		if(c == 0){
			cout << "0\n";
			continue;
		}

		//cout << penta[0] << " " << penta[1] << " " << penta[2] << " " << penta[3] << "\n";
		auto pos  = lower_bound(penta.begin(), penta.end(), c);

		auto prevPos = prev(pos);
		if(c - *prevPos <= *pos - c) cout << *prevPos << "\n";
		else cout << *pos << "\n";
	}
}