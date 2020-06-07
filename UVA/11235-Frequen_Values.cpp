#include<bits/stdc++.h>
using namespace std;

vector< int > st;
vector< int > A;
vector< int > input;
int n;

int left(int p){ return p >> 1; }
int right(int p){ return (p << 1) + 1; }

void build(int p, int L, int R){
	if(L == R) st[p] = L;
	else{
		build(left(p), L, (L + R) / 2);
		build(right(p), (L + R) / 2 + 1, R);
		
		int p1 = st[left(p)];
		int p2 = st[right(p)];

		st[p] = (A[p1] >= A[p2]) ? p1 : p2;
	}
}

int rmq(int p, int L, int R, int i, int j){
	if(i > R || j < L) return -1;
	if(L >= i && R <= j) return st[p];

	int p1 = rmq(left(p), L, (L + R) / 2, i, j);
	int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	return (A[p1] >= A[p2] ? p1 : p2);
}

int rmq(int i, int j){
	return rmq(1, 0, n - 1, i, j);
}

void segmentTree(){
	int i;
	for(i = 0; i < 4 * n; i++) st.push_back(0);

	build(1, 0, n - 1);
}

int main(){
	int q, i, j, a, cant, num, pos;
	cin >> n;

	while(n != 0){
		cin >> q;
		cant = 1;
		pos = 1;
		cin >> a;
		num = a;
		for(i = 1; i < n; i++){
			cin >> a;
			input.push_back(a);
			if(num == a){
				pos++;
				cant++;
			}
			else{
				for(j = 0; j < pos; j++){
					A.push_back(cant);
				}
				pos = 1;
				cant = 1;
				num = a;
			}

			if(i == n - 1){
				for(j = 0; j < pos; j++){
					A.push_back(cant);
				}
			}
		}

		segmentTree();

		while(q--){
			cin >> i >> j;
			if(input[i] == input[j]) cout << j - i + 1 << "\n";
			else{
				cout << A[rmq(i - 1, j - 1)] << "\n";
			}
			
		}

		cin >> n;
	}
}