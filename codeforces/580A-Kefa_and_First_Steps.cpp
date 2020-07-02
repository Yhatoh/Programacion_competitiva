#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, a, a_i, len, lenMax;
	cin >> n;

	lenMax = -1;
	len = 0;
	a_i = -1;
	while(n--){
		cin >> a;
		if(a_i <= a){
			len++;
		}
		else{
			if(len > lenMax) lenMax = len;
			len = 1;
		}
		a_i = a;
	}
	if(len > lenMax) lenMax = len;
	cout << lenMax << "\n";
	return 0;
}