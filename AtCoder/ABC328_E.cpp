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

struct UnionFind {
  vector<int> e;
  UnionFind(int n) { e.assign(n, -1); }
  int findSet (int x) {
    return (e[x] < 0 ? x : e[x] = findSet(e[x]));
  }
  bool sameSet (int x, int y) { return findSet(x) == findSet(y); }
  int size (int x) { return -e[findSet(x)]; }
  bool unionSet (int x, int y) {
    x = findSet(x), y = findSet(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
  }
};

struct arco {
  ll i, j, w;
  arco(ll x_, ll y_, ll z_) : i(x_), j(y_), w(z_) {}
};

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    ll n, m, k;
    cin >> n >> m >> k;
    vector< arco > arcs;
    fn(i, m) {
      ll u, v, w;
      cin >> u >> v >> w;
      u--; v--;
      arcs.push_back(arco(u, v, w));
    }

    ll maxi = 1000000000000000000;
    flr(i, 1, (1 << m)) {
      cout << i << "\n";
      UnionFind checker(n);
      ll total = 0;
      bool flag = true;
      fn(j, m) {
        if(i & (1 << j)) {
          if(checker.sameSet(arcs[j].i, arcs[j].j)) {
            flag = false;
            break;
          }
          checker.unionSet(arcs[j].i, arcs[j].j);
          total = (total + arcs[j].w) % k;
        }
      }
      if(checker.size(0) == n && flag && total < maxi) {
        maxi = total;
      }
    }
    cout << maxi << "\n";
  }
  return 0;
}
