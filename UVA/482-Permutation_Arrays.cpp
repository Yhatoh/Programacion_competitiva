#include<bits/stdc++.h>

using namespace std;

int main(){
	int cas,n,i;
	char space;
	cin >> cas;
	while(cas--){
		vector<int> numbers;
		
		scanf("%d%c",&n,&space);
		while(space != '\n'){
			numbers.push_back(n);
			scanf("%d%c",&n,&space);
		}
		numbers.push_back(n);
		vector<string> numbers2(numbers.size());

		for (i = 0; i < numbers.size(); ++i){
			cin >> numbers2[numbers[i]-1];
		}

		for (i = 0; i < numbers2.size(); ++i){
			cout << numbers2[i] << "\n";
		}
		if(cas != 0) cout << "\n";
	}
	return 0;
}