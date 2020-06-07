#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< ll > ST;
vector< ll > A;
vector< ll > lazy;
int n;

void build(int ind, int i, int j) {
    if(i == j) {
        ST[ind] = A[i];
    } else {
        int m = (i + j) / 2;
        build(ind * 2, i, m);
        build((ind * 2) + 1, m + 1, j);
        ST[ind] = min(ST[ind * 2], ST[(ind * 2) + 1]);
    }
}

void segmentTree(){
	ST.assign(4 * n, 0);
	lazy.assign(4 * n, 0);
	build(1, 0, n - 1);
}

void update(int a, int b, int node, int i , int j , ll val){
    if(lazy[node] != 0){
        ST[node] += lazy[node];
        if(i != j){
            lazy[node * 2] += lazy[node];
            lazy[(node * 2) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(!(j < a || i > b)){
	    if(i >= a && j <= b){
	        ST[node] += val;
	        if(i != j){
	            lazy[node * 2] += val;
	            lazy[(node * 2) + 1] += val;
	        }
	        return;
	    }
	    update(a, b, node * 2, i,(i + j) / 2, val);
	    update(a, b, (node * 2) + 1, (i + j) / 2 + 1, j, val);
	    
	    ST[node] = min(ST[node * 2], ST[(node * 2) + 1]);
	}

}

void update2(int a, int b, ll val){
    update(a, b, 1, 0, n-1, val);
}

ll query(int a, int b, int node,int i, int j){
    if(j < a || i > b) return 1000000000;
    if(lazy[node] != 0){
        ST[node] += lazy[node];
        if(i != j){
            lazy[node * 2] += lazy[node];
            lazy[(node * 2) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(i >= a && j <= b) return ST[node];
    
    ll x = query(a, b, node * 2, i, (i + j) / 2);
    ll y = query(a, b, (node * 2) + 1, (i + j) / 2 + 1, j);

    return min(x, y);
}

ll query2(int a, int b){
    return query(a, b, 1, 0, n-1);
}

int main(){
	int m, a, i, lf, rg, lf2, rg2, v;
	char c;
	cin >> n;

	for(i = 0; i < n; i++){
		cin >> a;
		A.push_back(a);
	}
	segmentTree();
	cin >> m;
	while(m--){
		scanf("%d%c", &lf, &c);
		scanf("%d%c", &rg, &c);
		if(c == ' '){
			scanf("%d%c", &v, &c);
			if(lf > rg){
				rg2 = n - 1;
				lf2 = 0;

				update2(lf, rg2, v);
				update2(lf2, rg, v);
			}
			else update2(lf, rg, v);
		}
		else{
			if(lf > rg){
				rg2 = n - 1;
				lf2 = 0;
				ll answer1 = query2(lf, rg2);
				ll answer2 = query2(lf2, rg);
				if(answer1 <= answer2) cout << answer1 <<"\n";
				else cout << answer2 << "\n";
			}
			else cout << query2(lf, rg) << "\n";
		}
	}
	return 0;
}