#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< ll > FT;

void fenwickTree(int n){
	FT.assign(n + 1, 0);
}

ll query(int n){
	int i;
	ll sum = 0;
	for(i = n; i; i -= (i & (-i)))
		sum += FT[i];
	return sum;
}

void update(int i, ll x){
	for(; i < FT.size(); i += (i & (-i)))
		FT[i] += x; 
}

void updateRange(int l, int r, ll x){
	update(l, x);
	update(r + 1, -x);
}

int readCumFreq(int index){
	int sum = 0;
	while(index > 0){
		sum += FT[index];
		index -= (index & -index);
	}
	return sum;
}

void printfFT(){
	for(int i = 0; i <= FT.size(); i++)
		cout << FT[i] << " ";
}

int main(){
	int n, q, i, l, r;
	ll sumAcum;
	cin >> n >> q;

	fenwickTree(n);
	vector< ll > as(n);
	vector< ll > mult(n);

	i = 0;
	while(n > i){
		cin >> as[i];
		i++;
	}

	sort(as.begin(), as.end());
	while(q--){
		cin >> l >> r;
		updateRange(l, r, 1);
	}

	for(i = 1; i <= n; i++){
		mult[i - 1] = readCumFreq(i);
	}

	sort(mult.begin(), mult.end());
	sumAcum = 0;
	i = 0;
	while(n > i)
		sumAcum += as[i] * mult[i++];
	cout << sumAcum << "\n";

	
	return 0;
}