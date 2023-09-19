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

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
  os << "[";
  for(uint64_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if(i != vec.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}

typedef long long ll;

template< class T, ll child(ll), ll parent(ll) >
struct FenwickTree {
  vector< T > bit;
  ll n;

  FenwickTree(vector< T > v) : n(v.size()) {
    bit.assign(n, 0);
    for(ll i = 0; i < v.size(); i++)
      update(i, v[i]);
  }

  ll query(ll idx) {
    ll ret = 0;
    for(; idx >= 0; idx = child(idx) - 1)
      ret += bit[idx];
    return ret;
  }

  ll query(ll l, ll r) {
    return query(r) - query(l - 1);
  }

  void update(ll idx, ll delta) {
    for(; idx < n; idx = parent(idx))
      bit[idx] += delta;
  }
};

ll child(ll n) { return n & (n + 1); }
ll parent(ll n) { return n | (n + 1); }

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  ll t = 1;
  cin >> t;
  ll cases = 1;
  while(t--) {
    ll n, q;
    cin >> n >> q;
    vector< ll > vec(n);
    fn(i, n) cin >> vec[i];

    FenwickTree< ll, child, parent > f(vec);

    cout << "Case " << cases++ << ":\n";
    while(q--) {
      ll op, i;
      cin >> op >> i;
      if(op == 1) {
        ll val = f.query(i, i);
        cout << val << "\n";
        f.update(i, -val);
      } else if(op == 2) {
        ll v; cin >> v;
        f.update(i, v);
      } else {
        ll j; cin >> j;
        cout << f.query(i, j) << "\n";
      }
    }
  }
  return 0;
}
