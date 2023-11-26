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

void dfs(vvi &g, vi &vis, vi &dist, int node) {
  vis[node] = 1;
  fn(i, g[node].size()) {
    int v = g[node][i];
    if(!vis[v]) {
      dist[v] = dist[node] + 1;
      dfs(g, vis, dist, v);
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
    int n;
    cin >> n;
    vvi g(n);

    fn(i, n - 1) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    vi dist(n, 0);
    vi vis(n, 0);
    dfs(g, vis, dist, 0);

    int max_i = 0;
    flr(i, 1, n) {
      if(dist[max_i] < dist[i]) {
        max_i = i;
      }
    }

    vi dist2(n, 0);
    vi vis2(n, 0);
    int a = max_i;
    dfs(g, vis2, dist2, a);

    max_i = 0;
    flr(i, 1, n) {
      if(dist2[max_i] < dist2[i]) {
        max_i = i;
      }
    }
    int b = max_i;

    vi dist3(n, 0);
    vi vis3(n, 0);
    dfs(g, vis3, dist3, b);

    fn(i, n) {
      cout << max(dist2[i], dist3[i]) << " ";
    }
    cout << "\n";
  }
  return 0;
}
