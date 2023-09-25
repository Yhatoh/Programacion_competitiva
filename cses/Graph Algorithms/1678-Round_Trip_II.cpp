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

int dfs(vvi &g, vi &vis, vi &p, int &start, int &end, int n) {
  vis[n] = 1;

  fn(i, g[n].size()) {
    int v = g[n][i];
    if(vis[v] == 0) {
      p[v] = n;
      if(dfs(g, vis, p, start, end, v)) return 1;
    } else if(vis[v] == 1) {
      start = v;
      end = n;
      return 1;
    }
  }
  vis[n] = 2;
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
    vi parent(n, -1);
    int start, end;
    bool cycle = false;
    fn(i, n) {
      if(visited[i] == 0) {
        cycle = dfs(g, visited, parent, start, end, i);
        if(cycle) break;
      }
    }

    if(!cycle) cout << "IMPOSSIBLE\n";
    else {
      vector< int > ans;
      ans.push_back(start);
      for(int i = end; i != start; i = parent[i]) {
        ans.push_back(i);
      }
      ans.push_back(start);
      reverse(ans.begin(), ans.end());
      cout << ans.size() << "\n";
      for(auto x : ans) cout << x + 1 << " ";
      cout << "\n";
    }
  }
  return 0;
}
