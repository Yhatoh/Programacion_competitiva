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

struct Dinic {
  struct Edge { ll to, rev; ll f, c; };
  ll n, t_; vector<vector<Edge>> G;
  vector<ll> D;
  vector<ll> q, W;
  bool bfs(ll s, ll t) {
    W.assign(n, 0); D.assign(n, -1); D[s] = 0;
    ll f = 0, l = 0; q[l++] = s;
    while (f < l) {
      ll u = q[f++];
      for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
        D[e.to] = D[u] + 1, q[l++] = e.to;
    }
    return D[t] != -1;
  }
  ll dfs(ll u, ll f) {
    if (u == t_) return f;
    for (ll &i = W[u]; i < (ll)G[u].size(); ++i) {
      Edge &e = G[u][i]; ll v = e.to;
      if (e.c <= e.f || D[v] != D[u] + 1) continue;
      ll df = dfs(v, min(f, e.c - e.f));
      if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
    }
    return 0;
  }
  Dinic(ll N) : n(N), G(N), D(N), q(N) {}
  void add_edge(ll u, ll v, ll cap) {
    G[u].push_back({v, (ll)G[v].size(), 0, cap});
    G[v].push_back({u, (ll)G[u].size() - 1, 0, 0}); // Use cap instead of 0 if bidirectional
  }
  ll max_flow(ll s, ll t) {
    t_ = t; ll ans = 0;
    while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
    return ans;
  }
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
    Dinic d(n);
    fn(i, m) {
      ll a, b;
      ll c;
      cin >> a >> b >> c;
      a--; b--;
      d.add_edge(a, b, c);
    }
    cout << d.max_flow(0, n - 1) << "\n";
  }
  return 0;
}
