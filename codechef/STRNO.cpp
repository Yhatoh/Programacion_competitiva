#include<bits/stdc++.h>

using namespace std;

int primos[1000000];

int es_primo(int N)
{
	if(primos[N] == -1){
		int k, raiz;

		raiz = (int) sqrt(N);

		for( k=2; N % k && k <= raiz; k++);


		if(k==raiz+1){
			primos[N] = 1;
	   		return 1;
	   	}

	   	primos[N] = 0;
		return 0; 
	}
	return primos[N];
}

int powa(int a, int k){
    if(k == 1) return a;
    int temp = powa(a, k/2);
    if(k%2 == 0){
        return temp*temp;
    }
    else{
        return temp*temp*a;
    }
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	
	int T, cantPrimos, i;
    cin >> T;

    for(i = 0; i < 1000000; i++) primos[i] = -1;

    while(T--){
        int X, K;
        cin >> X >> K;

        if(K > 32) {
            cout << "0\n";
            continue;
        }
        if(X < powa(2, K)){
            cout << "0\n";
            continue;
        }

        cantPrimos = 0;
        for(i = 1; i <= sqrt(X); i++)
	        if(es_primo(i) && X % i == 0)
	        	cantPrimos++;

	    if(cantPrimos < K) cout << "0\n";
	    else cout << "0\n";
	        	
    }

	return 0;
}