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

int dfs(vvi &g, vi &vis, vi &top, int n) {
  vis[n] = 1;
 
  fn(i, g[n].size()) {
    int v = g[n][i];
    if(vis[v] == 0) {
      if(dfs(g, vis, top, v)) return 1;
    } else if(vis[v] == 1) {
      return 1;
    }
  }
  vis[n] = 2;
  top.push_back(n);
  return 0;
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
    fn(i, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
    }

    vi visited(n, 0);
    vi top_sort;
    bool cycle = false;
    fn(i, n) {
      if(visited[i] == 0) {
        cycle = cycle || dfs(g, visited, top_sort, i);
      }
    }
    reverse(top_sort.begin(), top_sort.end());
    if(!cycle) {
      vi d(n, 0);
      vi p(n, -1);
      d[0] = 1;
      fn(i, n) {
        for(auto x : g[top_sort[i]]) {
          if(d[x] < d[top_sort[i]] + 1 && d[top_sort[i]]) {
            d[x] = d[top_sort[i]] + 1;
            p[x] = top_sort[i];
          }
        }
      }
      vi ans;
      for(int i = n - 1; i != -1; i = p[i]) ans.push_back(i);
      if(ans.size() < 2) cout << "IMPOSSIBLE\n";
      else {
        cout << ans.size() << "\n";
        frle(i, 0, ans.size() - 1) cout << ans[i] + 1 << " ";
        cout << "\n";
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
  return 0;
}
