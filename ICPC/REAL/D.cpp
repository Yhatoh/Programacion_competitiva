#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo (int x) {
    return x && (!(x&(x-1)));
}
 

int main(){

	int n;
	cin >> n;

	vector< int > candies(n);
	for(int i = 0; i < n; i++){
		cin >> candies[i];
	}


	sort(candies.begin(), candies.end());

	vector< int > cuantoshay(candies[n - 1] + 1, 0);

	int prev = candies[0];
	int cuantos = 1;
	for(int i = 1; i < n; i++){
		if(candies[i] == prev){
			prev = candies[i];
			cuantos++;
		} else {
			cuantoshay[prev] = cuantos;
			prev = candies[i];
			cuantos = 1;
		}
	}

	cuantoshay[prev] = cuantos;


	for(int i = 1; i < (int) candies[n - 1] + 1; i++){
		cuantoshay[i] += cuantoshay[i - 1] / 2;
		cuantoshay[i - 1] = cuantoshay[i - 1] % 2;
	}


	int booli = true;
	int cont = 0;
	int where1 = -1;
	int where2 = -1;
	for(int i = 0; i < (int) candies[n - 1] + 1; i++){
		if(cuantoshay[i] > 0){
			cont++;
			if(where1 == -1){
				where1 = i;
			} else if(where2 == -1){
				where2 = i;
			}

			if(cont > 2) break;
		}
	}

	if(cont == 2){
		if(isPowerOfTwo(cuantoshay[where1]) && isPowerOfTwo(cuantoshay[where2]))
			cout << "Y\n";
		else cout << "N\n";
	} else if(cont == 1){
		if(cuantoshay[where1] > 1){
			if(cuantoshay[where1] % 2 && isPowerOfTwo(cuantoshay[where1] - 1))
				cout << "Y\n";
			else if(cuantoshay[where1] % 2 == 0 && isPowerOfTwo(cuantoshay[where1]))
				cout << "Y\n";
			else cout << "N\n";
		}
		else cout << "N\n";
	} else cout << "N\n";
	return 0;
}