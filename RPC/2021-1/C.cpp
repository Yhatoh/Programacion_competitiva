#include<bits/stdc++.h>

using namespace std;

int main(){
	int m, n, i;
	cin >> m >> n;
	while(m != 0 && n != 0){
		vector< int > a;
		vector< int > b;
		for(i = 0; i < m; i++){
			int c;
			cin >> c;
			a.push_back(c);
		}
		for(i = 0; i < n; i++){
			int c;
			cin >> c;
			b.push_back(c);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int first, second, unionSize, intersectSize, diff1Size, diff2Size;
		first = second = 0;
		unionSize = intersectSize = diff1Size = diff2Size = 0;
		while(first < m && second < n){
			if(a[first] == b[second]){
				unionSize++;
				intersectSize++;
				first++;
				second++;
			} else if(a[first] < b[second]){
				unionSize++;
				diff1Size++;
				first++;
			} else {
				unionSize++;
				diff2Size++;
				second++;
			}
		}

		while(first < m){
			first++;
			unionSize++;
			diff1Size++;
		}

		while(second < n){
			second++;
			unionSize++;
			diff2Size++;
		}

		cout << diff1Size << " " << intersectSize << " " << diff2Size << " " << unionSize << "\n";
		cin >> m >> n;
	}
	return 0;
}