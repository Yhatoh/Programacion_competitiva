#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		map< string, int > words;
		map< string, int >::iterator it;
		int i;
		for(i = 0; i < n * 3; i++){
			string problem;
			int cs;
			cin >> problem >> cs;
			it = words.find(problem);
			if(it == words.end()) {
				words.insert(pair< string, int >(problem, cs));
			} else {
				it->second += cs;
			}
		}

		vector< int > problems;
		for(it = words.begin(); it != words.end(); it++){
			problems.push_back(it->second);
		}

		sort(problems.begin(), problems.end());
		for(i = 0; i < problems.size() - 1; i++){
			cout << problems[i] << " ";
		}
		cout << problems[i] << "\n";
	}
}