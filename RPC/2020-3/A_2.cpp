#include<bits/stdc++.h>

using namespace std;

typedef vector< double > vpid;
typedef vector< vpid > vv;

int main(){
	int number = 15;
	int j;
	for(j = number; j > 0; j = (number & (j - 1))){
		cout << j << "\n";		
	}

	return 0;
}

