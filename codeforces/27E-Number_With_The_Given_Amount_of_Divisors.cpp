#include<bits/stdc++.h>
using namespace std;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

long long backtracking(int cantDiv, int currPrime, long long number, int n){
	if(cantDiv == n) return number;
	long long i;
	long long minNumber, option;
	minNumber = 1e18;

	for(i = 1; cantDiv * (i + 1) <= n; i++){
		number = number * primes[currPrime];
		if(number > minNumber) break;
		
		option =  backtracking(cantDiv * (i + 1), currPrime + 1, number, n);
		if(minNumber > option) 
			minNumber = option;

	}

	return minNumber;
}

int main(){
	
	int n, cantDiv, currPrime, i;
	long long number;

	cantDiv = number = 1;
	currPrime = 0;

	cin >> n;

	cout << backtracking(cantDiv, currPrime, number, n) << "\n";
	return 0;
}