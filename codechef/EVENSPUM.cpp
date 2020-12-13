#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	
	int t;
	cin >> t;
	while(t--){
		long long A, B;
		cin >> A >> B;

		long long cantEvenA, cantOddA, cantEvenB, cantOddB;
		cantEvenA = cantOddA = cantEvenB = cantOddB = 0;

		if(A % 2){
			cantOddA++;
			A--;
		} 
		cantEvenA += A / 2;
		cantOddA += A / 2;

		if(B % 2){
			cantOddB++;
			B--;
		} 
		cantEvenB += B / 2;
		cantOddB += B / 2;
		
		cout << cantOddB * cantOddA + cantEvenB * cantEvenA << "\n"; 
	}
	return 0;
}