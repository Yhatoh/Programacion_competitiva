#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, i;
	cin >> n;
	vector< pair< int, int > > professors(n);

	for(i = 0; i < n; i++){
		professors[i].first = i;
		cin >> professors[i].second;
	}

	int counter;
	int pos = 0;
	while(professors.size() > 1){
		//cout << "number from " << professors[pos].first << "\n";
		int k = professors[pos].second;

		pos = (pos + k - 1) % professors.size();

		//cout << "eliminated " << pos << " " << professors[pos].first << "\n";
		professors.erase(professors.begin() + pos);	

		pos = (pos) % professors.size();
		
	}

	cout << professors[0].first + 1 << "\n";
	return 0;
}