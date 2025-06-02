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

void Dijsktra(vvpll &G, vector< multiset< ll > > &D, int a, int k) {
  D[a].insert(0);
  priority_queue< pll, vpll, greater<pll>> PQ;
  PQ.push(pll(0, a));
  while(!PQ.empty()) {
    ll u = PQ.top().second;
    ll d = PQ.top().first;
    PQ.pop();
    if(D[u].size() > 1 && d > *prev(D[u].end())) continue;
    // only in case that final node exists
    for(pll next : G[u]) {
      ll v = next.first;
      ll w = next.second;
      if(D[v].size() < k) {
        D[v].insert(d + w);
        PQ.push({d + w, v});
      } else if(*prev(D[v].end()) > d + w) {
        auto itr = D[v].end();
        itr = prev(itr);
        D[v].erase(itr);
        D[v].insert(d + w);
        PQ.push({d + w, v});
      }
    }
  }
}

int main() {
  int t = 1;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vvpll g(n);
    fn(i, m) {
      ll a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      g[a].push_back({b, c});
    }

    vector< multiset< ll > > one_to(n);
    Dijsktra(g, one_to, 0, k);

    for(auto x : one_to[n - 1]) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
