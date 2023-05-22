#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(2);
	int t;
	cin >> t;
	string word;
	while(t--){
		cin >> word;
		int left, right;
		left = right = 0;

		bool findA = false;
		for(int i = 0; i < word.size(); i++){
			if(word[i] == 'a'){
				findA = true;
				left = i;
				right = i;
				break;
			}
		}

		if(left > 0) left--;
		if(right < word.size() - 1) right++;
		char lastLetter = 'a';

		bool booli = true;
		if(word.size() > 1 && findA){
			while(left >= 0 && right <= word.size() - 1){
				//cout << left << " " << right << " " << lastLetter << "\n";
				if(left >= 0 && word[left] == lastLetter + 1){
					left--;
					lastLetter++;
				} else if(right <= word.size() - 1 && word[right] == lastLetter + 1){
					right++;
					lastLetter++;
				} else {
					booli = false;
					break;
				}
			}
		}

		if(booli) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}