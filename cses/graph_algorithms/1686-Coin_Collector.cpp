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

template< typename T, typename T2 >
ostream& operator<<(ostream& os, const pair< T, T2 > &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

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

template< typename T >
ostream& operator<<(ostream& os, const set< T > &m) {
  os << "{";
  for(auto p : m) {
    os << "(" << p.first << "," << p.second << ")";
    os << " ";
  }
  os << "}";
  return os;
}

void dfs(vvll &g, vll &vis, vll &top, int node, int color) {
  vis[node] = color;
  fn(i, g[node].size()) {
    int v = g[node][i];
    if(vis[v] == 0) dfs(g, vis, top, v, color);
  }
  top.push_back(node);
}

void dfs(vvll &g, vll &comp, vll &vis, set< pair< ll, ll > > &edges, int node) {
  vis[node] = 1;
  fn(i, g[node].size()) {
    int v = g[node][i];
    if(comp[node] != comp[v]) edges.insert({comp[node], comp[v]});
    if(vis[v] == 0)
      dfs(g, comp, vis, edges, v);
  }
}

void topsort(vvll &g, vll &vis, vll &top) {
  fn(i, g.size()) {
    if(vis[i] == 0)
      dfs(g, vis, top, i, 1);
  }
}

#define debug 1
int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vll coins(n);
    fn(i, n) cin >> coins[i];

    vvll g(n);
    vvll gr(n);
    fn(i, m) {
      ll a, b;
      cin >> a >> b;
      a--; b--;

      g[a].push_back(b);
      gr[b].push_back(a);
    }

    vll vis1(n, 0);
    vll top;

    topsort(g, vis1, top);

    vll vis2(n, 0);
    vll top2;

    int color = 1;
    frle(i, 0, top.size() - 1) {
      if(vis2[top[i]] == 0) {
        dfs(gr, vis2, top2, top[i], color);
        color++;
      }
    }

    fn(i, n) vis2[i]--;

    color--;
    vll metacoins(color, 0);
    fn(i, n)
      metacoins[vis2[i]] += coins[i];

    set< pair< ll, ll > > edges;
    vll vis3(n, 0);
    fn(i, n)
      if(vis3[i] == 0) dfs(g, vis2, vis3, edges, i);

    vvll meta_g(color);
    for(auto e : edges) {
      meta_g[e.first].push_back(e.second);
    }

    vll meta_vis(color, 0);
    vll meta_top;
    topsort(meta_g, meta_vis, meta_top);

    ll ans = 0;
    vll dp(color, 0);
    fn(i, color) dp[i] = metacoins[i];
    reverse(meta_top.begin(), meta_top.end());
    fn(i, meta_top.size()) {
      ll node = meta_top[i];
      fn(j, meta_g[node].size()) {
        ll v = meta_g[node][j];
        dp[v] = max(dp[v], dp[node] + metacoins[v]);
      }
    }
    fn(i, color) ans = max(ans, dp[i]);
    cout << ans << "\n";
  }
  return 0;
}
