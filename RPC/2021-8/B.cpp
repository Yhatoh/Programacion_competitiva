#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree{ 
    vector<ll>ST, lazy; 
    int n; 
 
    SegmentTree(vector<int> &a) { 
        this->n = a.size(); 
        ST.assign(4*n,0); 
        lazy.assign(4*n,0); 
        build(1, 0, n-1, a); 
    } 
 
    void build(int ind, int i, int j, vector<int> &a) { 
        if(i == j) { 
            ST[ind] = a[i]; 
        } else { 
            int m = (i+j)/2; 
            build(ind<<1, i, m, a); 
            build((ind<<1)+1, m+1, j, a); 
            ST[ind] = ST[ind<<1] + ST[(ind<<1)+1]; 
        } 
    } 
 
    void update(int a, int b, ll val){ 
        update(a,b,1,0,n-1,val); 
    } 
 
    void update(int a, int b, int node, int i , int j , ll val){ 
        /*if(lazy[node]!=0){ 
            ST[node]+=lazy[node]*(j-i+1); 
            if(i!=j){ 
                lazy[node<<1]+=lazy[node]; 
                lazy[(node<<1)+1]+=lazy[node]; 
            } 
            lazy[node]=0; 
        }*/ 
        if(j<a || i>b)return; 
        if(i>=a && j<=b){ 
            ST[node]+=val; 
            /*if(i!=j){ 
                lazy[node<<1]+=val; 
                lazy[(node<<1)+1]+=val; 
            }*/ 
            return; 
        } 
        update(a,b,node<<1,i,(i+j)/2,val); 
        update(a,b,(node<<1)+1,(i+j)/2+1,j,val); 
   
        ST[node]=ST[node<<1]+ST[(node<<1)+1]; 
  
    } 
 
    ll query(int a, int b){ 
        return query(a,b, 1,0,n-1); 
    } 
 
    ll query(int a, int b, int node,int i, int j){ 
        if(i>=a && j<=b) return ST[node]; 
        if(j<a || i>b) return 0; 
        /*if(lazy[node]!=0){ 
            ST[node]+=lazy[node]*(j-i+1); 
            if(i!=j){ 
                lazy[node<<1]+=lazy[node]; 
                lazy[(node<<1)+1]+=lazy[node]; 
            } 
            lazy[node]=0; 
        }*/ 
   
        ll x = query(a,b,node<<1,i,(i+j)/2); 
 
        ll y = query(a,b,(node<<1)+1,(i+j)/2+1,j); 
 
        return x + y; 
    } 
};

int main(){
    int q;
    int n;
    cin >> n >> q;
    vector< int > A;
    A.assign(n, 0);
    for (int i = 0; i < n; ++i){
        cin >> A[i];
    }

    SegmentTree ST(A);

    while(q--){
        char j;
        int a, b;

        cin >> j >> a >> b;
        if(j == 'q'){
            cout << ST.query(a - 1, b - 1) << "\n";
        } else {
            ST.update(a - 1, a - 1, b);
            A[a] += b;
        }
    }
}