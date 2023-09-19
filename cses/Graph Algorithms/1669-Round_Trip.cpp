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

typedef vector< int > vi;
typedef vector< vi > vvi;

int DFS(vvi &g, vi &ps, vi &res, vi &vis, int n, int p) {
  vis[n] = 1;
  ps[n] = p;

  int ret = 0;
  for(int v : g[n]) {
    if(vis[v] == 0) {
      ret = DFS(g, ps, res, vis, v, n);
      if(ret == 1) {
        if(res[0] != v && (res.size() == 1 || res[res.size() - 1] != res[0])) res.push_back(v);
        if(n == res[0]) res.push_back(n);
        return ret;
      }
    } else if(ps[n] != v) {
      res.push_back(v);
      return 1;
    }
  }

  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);

  int n, m;
  cin >> n >> m;
  vvi graph(n);
  fn(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vi visited(n, 0);
  vi ps(n, -1);
  vi res;

  fn(i, n) {
    if(visited[i] == 0) DFS(graph, ps, res, visited, i, -1);
    if(res.size() > 0) break;
  }

  if(res.size() == 0) cout << "IMPOSSIBLE\n";
  else {
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++) {
      cout << res[i] + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
