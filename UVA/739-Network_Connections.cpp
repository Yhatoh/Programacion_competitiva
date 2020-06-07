#include<bits/stdc++.h>

using namespace std;


vector<int> p;
vector<int> r;

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

		if(r[x] > r[y]) p[y] = x;
		else {
			p[x] = y;
			if(r[x] == r[y]) r[y]++;
		}
	}
}

void printUnion(){
	int i;
	for(i = 0; i < p.size(); i++) cout << p[i] << " " << r[i] << "\n";
}

int main(){
	
	int i, c, nComp, c1, c2, trueQuery, falseQuery;
	string line;
	char query[4];

	scanf("%d", &c);
	while(c--) {
		scanf("%d", &nComp);
		initUnion(nComp);
		trueQuery = 0;
		falseQuery = 0;
		
		getline(cin, line);
		getline(cin, line);
		if(line.length() != 0){
			while(1) {
				if(line.length() == 1) {getline(cin, line); break;}
				sscanf(line.c_str(), "%s %d %d", query, &c1, &c2);
				
				if(query[0] == 'c') unionSet(c1-1, c2-1);
				else {
					if(isSameSet(c1-1, c2-1)) trueQuery++;
					else falseQuery++;

				}
				if(line.length() == 0) break;
				getline(cin, line);
				
			}
			cout << trueQuery << "," << falseQuery << "\n";
			if(c) cout << "\n";
		}

	}
	return 0;
}