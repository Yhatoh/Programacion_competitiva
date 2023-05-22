#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< ll > ST1;
vector< ll > ST2;
vector< ll > ST3;
vector< ll > lazy1;
vector< ll > lazy2;
vector< ll > lazy3;
vector< ll > A;
ll n;

void build(ll ind, ll i, ll j) {
    if(i == j) {
        ST1[ind] = A[i];
        ST2[ind] = A[i];
        ST3[ind] = A[i];
    } else {
        ll m = (i + j) / 2;
        build(ind * 2, i, m);
        build((ind * 2) + 1, m + 1, j);
        ST1[ind] = max(ST1[ind * 2], ST1[(ind * 2) + 1]);
        ST2[ind] = max(ST2[ind * 2], ST2[(ind * 2) + 1]);
        ST3[ind] = max(ST3[ind * 2], ST3[(ind * 2) + 1]);
    }
}

void segmentTree(){
	ST1.assign(4 * n + 1, 0);
    ST2.assign(4 * n + 1, 0);
    ST3.assign(4 * n + 1, 0);
    lazy1.assign(4 * n + 1, 0);
    lazy2.assign(4 * n + 1, 0);
    lazy3.assign(4 * n + 1, 0);
	//build(1, 0, n - 1);
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val1, ll val2, ll val3){
    if (l > r)
        return;
    if (l == tl && r == tr) {
        ST1[v] += val1;
        ST2[v] += val2;
        ST3[v] += val3;
    } else {
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), val1, val2, val3);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, val1, val2, val3);
    }
}

ll query1(ll v, ll tl, ll tr, ll pos){
    if (tl == tr)
        return ST1[v];
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return ST1[v] + query1(v*2, tl, tm, pos);
    else
        return ST1[v] + query1(v*2+1, tm+1, tr, pos);
}

ll query2(ll v, ll tl, ll tr, ll pos){
    if (tl == tr)
        return ST2[v];
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return ST2[v] + query2(v*2, tl, tm, pos);
    else
        return ST2[v] + query2(v*2+1, tm+1, tr, pos);
}

ll query3(ll v, ll tl, ll tr, ll pos){
    if (tl == tr)
        return ST3[v];
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return ST3[v] + query3(v*2, tl, tm, pos);
    else
        return ST3[v] + query3(v*2+1, tm+1, tr, pos);
}

void query(ll i){
    cout << A[i - 1] + 
            query1(n, 1, n, i) + 
            (i * query2(n, 1, n, i)) + 
            ((i * i) * query3(n, 1, n, i)) << "\n";
}

int main(){
    ll q;
    cin >> n >> q;
    segmentTree();
    for(ll i = 0; i < n; i++){
        ll value;
        cin >> value;
        A.push_back(value);
    }
    ll l, r, x, option;

    while(q--){
        cin >> option;
        if(option == 1){
            cin >> l >> r >> x;
            update(1, 1, n, l, r, (x - l) * (x - l), 2 * (x - l), 1);
            //prllSeg();
        } else {
            cin >> x;
            query(x);
        }
    }
    return 0;
}