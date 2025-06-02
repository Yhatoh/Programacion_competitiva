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

struct Edge {
  ll a, b, c;
  Edge(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {}
};

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector< Edge > v;
    fn(i, m) {
      ll a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      v.push_back(Edge(a, b, c));
    }

    vll d(n, 10000000000000000);
    vi p(n, -1);
    fn(i, n - 1) {
      fn(j, m) {
        if(d[v[j].b] > d[v[j].a] + v[j].c) {
          d[v[j].b] = d[v[j].a] + v[j].c;
          p[v[j].b] = v[j].a;
        }
      }
    }

    bool cycle = false;
    ll start;
    fn(j, m) {
      if(d[v[j].b] > d[v[j].a] + v[j].c) {
        d[v[j].b] = d[v[j].a] + v[j].c;
        p[v[j].b] = v[j].a;
        cycle = true;
        start = v[j].a;
      }
    }
    if(cycle) {
      fn(i, n) {
        start = p[start];
      }
      vll paths;
      paths.push_back(start);
      for(ll i = p[start]; i != start; i = p[i]) paths.push_back(i);
      paths.push_back(start);
      reverse(paths.begin(), paths.end());
      cout << "YES\n";
      fn(i, paths.size()) {
        cout << paths[i] + 1 << " ";
      }
      cout << "\n";
    } else cout << "NO\n";
  }
  return 0;
}
