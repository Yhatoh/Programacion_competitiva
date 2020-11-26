#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, i, j, k, maxL;
	string word, maxW;
	maxL = 0;
	maxW = "";
	cin >> n;
	cin >> word;

	for(i = 0; i < n; i++){
		for(j = 0; j <= i; j++){
			//string subWord = word.substr(j, n - i + j);
			int size = n - i + j;
			bool itsPalin = true;

			for(k = 0; k < size / 2; k++){
				if(word[j + k] != word[j + size - (k + 1)]){
					itsPalin = false;
					break;
				}
			}
			
			if(itsPalin && size > maxL){
				maxL = size;
				maxW = word.substr(j, size);
			}
		}
	}
	cout << maxL << "\n" << maxW << "\n";
	return 0;
}