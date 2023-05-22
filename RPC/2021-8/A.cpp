/*t = int(input())

i = 0
total = 0
phones = []
while i < t:
	phone = input()
	phones.append(phone)
	i += 1

phones.sort()

for i in range(t):
	num = phones[i]
	lenNum = len(num)
	for j in range(i + 1, t):
		if len(phones[j]) <= lenNum:
			continue

		if num == phones[j][0:lenNum]:
			total += 1

print(total)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;

	vector< string > phones(t);
	for (int i = 0; i < t; ++i){
		cin >> phones[i];
	}

	sort(phones.begin(), phones.end());
	/*
	for (int i = 0; i < t; ++i){
		cout << phones[i] << " ";
	}
	cout <<"\n";
	*/
	int total = 0;
	for (int i = 0; i < t - 1; ++i){
		for (int j = i + 1; j < t; ++j){
			if(phones[j].length() <= phones[i].length()) continue;

			if(phones[j][0] != phones[i][0]) break;

			int k;
			for(k = 0; k < phones[i].length(); k++){
				if(phones[j][k] != phones[i][k]) break;
			}

			if(k == phones[i].length()) total++;

 		}
	}
	cout << total << "\n";
	return 0;
}