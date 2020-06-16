#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, k, n, i;
	string tables;
	cin >> t;
	while(t--){
		cin >> n >> k >> tables;

		int start, end, start2, end2, answer;

		answer = 0;
		start = end = start2 = end2 = -1;
		for(i = 0; i < n; i++){
			if(start == -1 && tables[i] == '1'){
				start = i;
				answer += (start) / (k + 1);
			}
			else if(tables[i] == '1'){
				end2 = i;
				if(end2 - start - 1 - k > 0){
					answer += (end2 - start - 1 - k) / (k + 1);
				}
				start = end2;
				end2 = -1;
			}
		}

		if(start == -1) cout << (n + k) / (k + 1) << "\n";
		else{
			answer += (n - start - 1) / (k + 1);
			cout << answer << "\n";
		}
		
	}
	return 0;
}