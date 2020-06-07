#include<bits/stdc++.h>

using namespace std;


vector<int> p;
vector<int> r;
vector< vector< int > > merges;

void initUnion(int n){
	int i;
	if(p.size() != 0) p.clear();
	if(r.size() != 0) r.clear();
	for(i = 0; i < n; i++) {
		p.push_back(i);
		r.push_back(0);
	}
}

int findSet(int i){
	return (p[i] == i ? i : (p[i] = findSet(p[i])));
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j){
	if(!isSameSet(i, j)) {
		int x,y;
		x = findSet(i);
		y = findSet(j);

		if(r[x] > r[y]){
			p[y] = x;
			merges[x].insert(merges[x].end(), merges[y].begin(), merges[y].end());
		}
		else {
			p[x] = y;
			merges[y].insert(merges[y].end(), merges[x].begin(), merges[x].end());
			if(r[x] == r[y]) r[y]++;
		}
	}
}

void printUnion(){
	int i;
	for(i = 0; i < p.size(); i++) cout << i + 1 << " " << p[i] + 1<< " " << r[i] << "\n";
}

int main(){
	int n, x, y, BigPapa, i;
	cin >> n;
	initUnion(n);

	vector<int> chiquito(1);
	for(i = 0; i < n; i++){
		chiquito[0] = i;
		merges.push_back(chiquito);
	}

	i = 1;
	while(n > i){
		cin >> x >> y;
		unionSet(x - 1, y - 1);
		i++;
	}


	BigPapa = findSet(0);

	for(i = 0; i < n; i++){

		cout << merges[BigPapa][i] + 1 << "\n";
	}
	return 0;
}