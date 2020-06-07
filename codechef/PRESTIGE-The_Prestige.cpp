#include<bits/stdc++.h>

using namespace std;

void print(vector<pair<long long int,long long int>> &first, vector<pair<long long int,long long int>> &second,int n){
	int i;
	cout << "1 Deck\n";
	cout << "Upper Values: ";
	for (i = 1; i < n+1; ++i){
		if(first[i].first == 1) cout << " ";
		cout << first[i].first << " ";
	}
	cout << "\n";
	cout << "Lower Values: ";
	for (i = 1; i < n+1; ++i){
		if(first[i].second == 1) cout << " ";
		cout << first[i].second << " ";
	}
	cout << "\n";

	cout << "2 Deck\n";
	cout << "Upper Values: ";
	for (i = 1; i < n+1; ++i){
		cout << " " << second[i].first << " ";
	}
	cout << "\n";
	cout << "Lower Values: ";
	for (i = 1; i < n+1; ++i){
		cout << " " << second[i].second << " ";
	}
	cout << "\n";
}

void type1(vector<pair<long long int,long long int>> &second, int l, int r){
	int i, aux1, aux2;
	for(i = l; i < (l+r)/2; i++){
		cout << "YA\n";
		cout << i << "\n";
		aux1 = second[i].first;
		aux2 = second[i].second;
		second[i].first = second[r+(l-i)].second;
		second[i].second = second[r+(l-i)].first;
		second[r+(l-i)].second = aux1;
		second[r+(l-i)].first = aux2;
	}
	if((r-(l-1))%2 == 1){
		aux1 = second[(r+l)/2+1].first;
		second[(r+l)/2+1].first = second[(r+l)/2+1].second;
		second[(r+l)/2+1].second = aux1;
	}
}

void type2(vector<pair<long long int,long long int>> &first, int k){
	int i, aux1, aux2;
	for(i = 1; i < k/2+1; i++){
		aux1 = first[i].first;
		aux2 = first[i].second;
		first[i].first = first[k+1-i].second;
		first[i].second = first[k+1-i].first;
		first[k+1-i].second = aux1;
		first[k+1-i].first = aux2;
	}
	if(k%2 == 1){
		aux1 = first[k/2+1].first;
		first[k/2+1].first = first[k/2+1].second;
		first[k/2+1].second = aux1;
	}
}

void type3(vector<pair<long long int,long long int>> &first, vector<pair<long long int,long long int>> &second, int a, int b, int c, int d){
	int i;
	int total = 0;
	for (i = 0; i < (b-a)+1; ++i){
		total = total + first[c+i].first*second[a+i].first;
	}
	cout << total << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);

	int n, m, i, t, l, r, k, a, b, c, d;
	cin >> n >> m;

	vector<pair<long long int,long long int>> first(n+1);
	vector<pair<long long int,long long int>> second(n+1);

	for(i = 1; i < n+1; i++){
		cin >> second[i].first;
		first[i].first = 1;
	}

	for(i = 1; i < n+1; i++){
		cin >> second[i].second;
		first[i].second = -1;
	}
	print(first,second,n);
	cout << "\n";
	while(m--){
		cin >> t;
		if(t == 1){
			cin >> l >> r;
			type1(second,l,r);
		}
		else if(t == 2){
			cin >> k;
			type2(first,k);
		}
		else{
			cin >> a >> b >> c >> d;
			type3(first,second,a,b,c,d);
		}
		print(first,second,n);
		cout << "\n";
	}
	return 0;
}