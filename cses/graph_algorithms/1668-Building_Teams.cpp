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

void dfs(vector< vector< int > > &g, vector< int > &visited, vector< int > &colors, int node, bool color) {
  visited[node] = 1;
  colors[node] = color;
  fn(i, (int) g[node].size()) {
    int v = g[node][i];
    if(visited[v] == 0) {
      dfs(g, visited, colors, v, !color);
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
    vector< vector< int > > g(n);
    vector< pair< int, int > > edges(m);
    fn(i, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
      edges[i].first = a;
      edges[i].second = b;
    }

    vector< int > visited(n, 0);
    vector< int > colors(n, -1);
    int color = 1;
    fn(i, n) {
      if(visited[i] == 0)
        dfs(g, visited, colors, i, color);
    }

    bool flag = true;
    fn(i, m) {
      if(colors[edges[i].first] == colors[edges[i].second]) {
        flag = false;
        break;
      }
    }

    if(flag) {
      fn(i, n) cout << colors[i] + 1 << " ";
      cout << "\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
  return 0;
}
