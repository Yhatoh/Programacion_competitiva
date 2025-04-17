/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define dbg(var) cout << #var << " = " << var << endl;
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define feach(x, ds) for(auto &x : ds)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;
typedef long double ld; typedef vector< ld > vld;
typedef vector< vld > vvld; typedef pair< ld, ld > pldld;
typedef vector< pldld > vpldld; typedef vector< vpldld >  vvpldld;

void dfs(vvi &g, vi &vis, set< pii > &check, int comp, int u, int type) {
  vis[u] = comp;
  feach(v, g[u]) {
    bool visit = false;
    if(type && vis[v] == -1) {
      visit = true;
    } else if(!type && vis[v] == -1 && check.find({u, v}) == check.end()) {
      visit = true;
    }
    if(visit)
      dfs(g, vis, check, comp, v, type);
  }
}

void exec_dfs(vvi &g, vi &vis,
              set< pii >& check, int &comps, int type) {
  comps = 0;
  fn(i, g.size()) {
    if(vis[i] == -1) {
      dfs(g, vis, check, comps, i, type);
      comps++;
    }
  }
}

void read_graph(vvi &g, int m) {
  fn(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
}

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  cin >> t;
  while(t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vvi G(n);
    vi vis_G(n, -1);
    vvi F(n);
    vi vis_F(n, -1);

    read_graph(F, m1);
    read_graph(G, m2);

    set< pair< int, int > > check;
    int comps_G = 0;
    exec_dfs(G, vis_G, check, comps_G, 1);

    int remove = 0;
    fn(u, n) {
      feach(v, F[u]) {
        if(vis_G[u] != vis_G[v] &&
           check.find({u, v}) == check.end()) {
          remove++;
          check.insert({u, v});
          check.insert({v, u});
        }
      }
    }

    int comps_F = 0;
    exec_dfs(F, vis_F, check, comps_F, 0);

    cout << remove + (comps_F - comps_G) << "\n";
  }
  return 0;
}
