/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

template<class T, T _m(T, T)>
struct persistent_segment_tree {
  vector<T> ST;
  vector<int> L, R;
  int n, rt;
  persistent_segment_tree(int n): ST(1, T()), L(1, 0), R(1, 0), n(n), rt(0) {}
  int new_node(T v, int l = 0, int r = 0) {
    int ks = ST.size();
    ST.push_back(v); L.push_back(l); R.push_back(r);
    return ks;
  }
  int update(int k, int l, int r, int p, T v) {
    int ks = new_node(ST[k], L[k], R[k]);
    if (l == r) {
      ST[ks] = v; return ks;
    }
    int m = (l + r) / 2, ps;
    if (p <= m) {
      ps = update(L[ks], l, m, p, v);
      L[ks] = ps;
    } else {
      ps = update(R[ks], m + 1, r, p, v);
      R[ks] = ps;
    }
    ST[ks] = _m(ST[L[ks]], ST[R[ks]]);
    return ks;
  }
  T query(int k, int l, int r, int a, int b) {
    if (l >= a and r <= b)
      return ST[k];
    int m = (l + r) / 2;
    if (b <= m)
      return query(L[k], l, m, a, b);
    if (a > m)
      return query(R[k], m + 1, r, a, b);
    return _m(query(L[k], l, m, a, b), query(R[k], m + 1, r, a, b));
  }
  int update(int k, int p, T v) {
    return rt = update(k, 0, n - 1, p, v);
  }
  int update(int p, T v) {
    return update(rt, p, v);
  }
  T query(int k, int a, int b) {
    return query(k, 0, n - 1, a, b);
  }
};

ll merge(ll a, ll b) { return a + b; }

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, q;
    cin >> n >> q;
    vll nums(n);
    fn(i, n) cin >> nums[i];
    persistent_segment_tree< ll, merge > ST(n);
    vi index;
    index.push_back(0);
    fn(i, n) index[0] = ST.update(index[0], i, nums[i]);
    while(q--) {
      int op;
      cin >> op;
      if(op == 1) {
        int k, a;
        ll x;
        cin >> k >> a >> x;
        k--; a--;
        index[k] = ST.update(index[k], a, x);
      } else if(op == 2) {
        int k, a, b;
        cin >> k >> a >> b;
        k--; a--; b--;
        cout << ST.query(index[k], a, b) << "\n";
      } else {
        int k;
        cin >> k;
        k--;
        index.push_back(index[k]);
      }
    }
  }
  return 0;
}
