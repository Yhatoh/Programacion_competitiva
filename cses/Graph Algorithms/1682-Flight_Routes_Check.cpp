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

void dfs(vvi &g, vi &vis, int node) {
  vis[node] = 1;
  fn(i, g[node].size()) {
    int v = g[node][i];
    if(vis[v] == 0) dfs(g, vis, v);
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
    vvi g(n);
    vvi g2(n);
    fn(i, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g2[b].push_back(a);
    }

    vi vis(n, 0);
    dfs(g, vis, 0);
    fn(i, n) {
      if(!vis[i]) {
        cout << "NO\n";
        cout << 1 << " " << i + 1 << "\n";
        return 0;
      }
    }

    vi vis2(n, 0);
    dfs(g2, vis2, 0);
    fn(i, n) {
      if(!vis2[i]) {
        cout << "NO\n";
        cout << i + 1 << " " << 1 << "\n";
        return 0;
      }
    }

    cout << "YES\n";
  }
  return 0;
}
