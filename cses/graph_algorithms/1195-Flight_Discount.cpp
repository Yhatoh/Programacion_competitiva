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

void Dijsktra(vvpll &G, vll &D, int a) {
  D[a] = 0;
  priority_queue< pll, vpll, greater<pll>> PQ;
  PQ.push(pll(0, a));
  while(!PQ.empty()) {
    ll u = PQ.top().second;
    ll d = PQ.top().first;
    PQ.pop();
    if(d > D[u]) continue;
    // only in case that final node exists
    for(pll next : G[u]) {
      ll v = next.first;
      ll w = next.second;
      if(D[v] > D[u] + w) {
        D[v] = D[u] + w;
        PQ.push(pll(D[v], v));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vvpll g(n);
    vvpll g2(n);
    fn(i, m) {
      ll a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      g[a].push_back({b, c});
      g2[b].push_back({a, c});
    }

    vector< ll > one_to(n, 1000000000000000);
    vector< ll > n_to(n, 1000000000000000);
    Dijsktra(g, one_to, 0);
    Dijsktra(g2, n_to, n - 1);

    ll min_cost = 1000000000000000;
    fn(i, n) {
      fn(j, g[i].size()) {
        min_cost = min(min_cost, one_to[i] + n_to[g[i][j].first] + g[i][j].second / 2);
      }
    }
    cout << min_cost << "\n";
  }
  return 0;
}
