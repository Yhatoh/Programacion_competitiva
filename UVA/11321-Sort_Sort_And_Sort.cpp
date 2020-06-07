#include<bits/stdc++.h>

using namespace std;

int m;
int n;

int antesQue(int a, int b) {
	if(a % m != b % m) return a % m < b % m;
	else if(abs(a) % 2 != abs(b) % 2){
		if(abs(a) % 2 == 1) return 1;
		return 0;
	}
	else if(abs(a) % 2 == 1){
		return !(a < b);
	}
	else{
		return a < b;
	}
}

void mergeSort(vector<int> &numeros, vector<int> &temp, int izq, int der){
	int i, i1, i2, med = (izq + der) / 2;
	if(izq == der) return;
	mergeSort(numeros, temp, izq, med);
	mergeSort(numeros, temp, med + 1, der);

	for(i = izq; i <= der; i++) temp[i] = numeros[i];
	i1 = izq; i2 = med + 1;

	for(i = izq; i <= der; i++){
		if(i1 == med + 1) numeros[i] = temp[i2++];
		else if(i2 > der) numeros[i] = temp[i1++];
		else if(antesQue(temp[i1], temp[i2])) numeros[i] = temp[i1++];
		else numeros[i] = temp[i2++];
	}

}

int main(){
	int i;

	cin >> n >> m;
	
	while(n != 0 || m != 0) {
		vector<int> numeros(n+1);
		vector<int> numeros2(n+1);
		for(i = 1; i <= n; i++) cin >> numeros[i];
		mergeSort(numeros, numeros2, 1, n);

		cout << n << " " << m << "\n";
		for(i = 1; i <= n; i++) cout << numeros[i] << "\n";
		cin >> n >> m;
	}
	cout << n <<  " " << m << "\n";
	return 0;
}