#include<bits/stdc++.h>
using namespace std;

int main(){
	int m, n, i;
	cin >> m;
	vector< int > books(m + 1);
	for(i = 1; i <= m; i++) cin >> books[i];

	cin >> n;
	while(n--){
		cin >> i;
		cout << books[i] << "\n";
		books.erase(books.begin() + i);
	}
	return 0;
}
