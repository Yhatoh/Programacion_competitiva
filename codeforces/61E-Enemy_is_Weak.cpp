#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< ll > FT;
vector< ll > FT2;


void fenwickTree(int n, int fenwick){
	if(fenwick) FT.assign(n + 1, 0);
	else FT2.assign(n + 1, 0);
}

ll query(int n, int fenwick){
	int i;
	ll sum = 0;
	for(i = n; i; i -= (i & (-i)))
		sum += (fenwick ? FT[i] : FT2[i]);
	return sum;
}

void update(int i, ll x, int fenwick){
	for(; i < (fenwick ? FT.size() : FT2.size()); i += (i & (-i)))
		if(fenwick) FT[i] += x; 
		else FT2[i] += x;
}

void printfFT(int fenwick){
	for(int i = 0; i < (fenwick ? FT.size() : FT2.size()); i++)
		cout << (fenwick ? FT[i] : FT2[i]) << " ";
	cout << "\n";
}

bool menorAMayor(ll x, ll y){
	return x < y;
}

int main(){
	int n, i, toInc;
	ll weakness;
	cin >> n;
	vector< ll > romansOriginal(n);
	vector< ll > romansOrdered(n);
	vector< ll > final(n);
	map<ll, ll> newPosition;
	for(i = 0; i < n; i++){ 
		cin >> romansOriginal[i];
		romansOrdered[i] = romansOriginal[i];
	}
	sort(romansOrdered.begin(), romansOrdered.end(), menorAMayor);
	//obtener en que posicion deberia estar romansOriginal[i], si es que ordenamos
	//de menor a mayor
	for(i = 0; i < n; i++) newPosition.insert(pair<ll,ll>(romansOrdered[i], i));
	for(i = 0; i < n; i++) final[i] = newPosition[romansOriginal[i]];
	
	fenwickTree(n, 1);
	fenwickTree(n, 0);
	weakness = 0;
	for(i = n-1; i >= 0; i--){
		weakness += query(final[i] + 1, 0);
		toInc = query(final[i] + 1, 1);
		//Pa que hacer update
		if(i != 0){
			update(final[i] + 1, toInc, 0);
			update(final[i] + 1, 1, 1);
		}
		//printfFT(1);
		//printfFT(0);
	}
	cout << weakness << "\n";
}