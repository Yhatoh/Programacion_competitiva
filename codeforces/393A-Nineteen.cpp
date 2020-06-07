#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int cantN, cantE, cantI, cantT, i;
	
	cin >> s;

	cantN = 0;
	cantE = 0;
	cantI = 0;
	cantT = 0;
	
	for(i = 0; i < s.length(); i++){
		if(s.at(i) == 'n') cantN++;
		else if(s.at(i) == 'e') cantE++;
		else if(s.at(i) == 't') cantT++;
		else if(s.at(i) == 'i') cantI++;	
	}

	i = 0;
	while(1){
		if(cantN >= 3){
			cantN -= 2;
			if(cantT >= 1){
				cantT--;
				if(cantI >= 1){
					cantI--;
					if(cantE >= 3){
						cantE -= 3;
						i++;
					}
					else break;
				}
				else break;
			}
			else break;
		}
		else break;
	}
	cout << i << "\n";
	return 0;
}