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
typedef long long ll;
typedef pair< int, ll > pii;
typedef vector< pii > vpii;
typedef vector< vpii > graph;

struct Edge {
  int a, b;
  ll c;
  Edge(int _a, int _b, ll _c) : a(_a), b(_b), c(_c) {}
};

void dfs(graph &g, vector< int > &vis, vector< Edge > &edges, int n) {
  vis[n] = 1;
  fn(i, g[n].size()) {
    edges.push_back(Edge(g[n][i].first, n, g[n][i].second));
    if(vis[g[n][i].first] == 0) dfs(g, vis, edges, g[n][i].first);
  }
}

void dfs2(graph &g, vector< int > &vis, vector< Edge > &edges, int n) {
  vis[n] = 1;
  fn(i, g[n].size()) {
    edges.push_back(Edge(n, g[n][i].first, g[n][i].second));
    if(vis[g[n][i].first] == 0) dfs2(g, vis, edges, g[n][i].first);
  }
}

int main() {
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector< Edge > edges;
    graph g(n);
    fn(i, m) {
      ll a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      g[b].push_back({a, c});
    }

    vector< int > vis(n, 0);
    dfs(g, vis, edges, n - 1);
    vector< ll > d(n, -10000000000000000);
    d[0] = 0;
    fn(i, n - 1) {
      fn(j, edges.size()) {
        int a, b; ll c;
        a = edges[j].a;
        b = edges[j].b;
        c = edges[j].c;
        d[b] = max(d[b], d[a] + c);
      }
    }

    bool cycle = false;
    graph g2(n);
    fn(i, edges.size()) {
      int a, b; ll c;
      a = edges[i].a;
      b = edges[i].b;
      c = edges[i].c;
      g2[a].push_back({b, c});
    }
    vector< Edge > edges2;
    fn(i, n) vis[i] = 0;
    dfs2(g2, vis, edges2, 0);
    /*
    fn(j, edges2.size()) {
      int a, b; ll c;
      a = edges2[j].a;
      b = edges2[j].b;
      c = edges2[j].c;
      cout << "edge[" << j << "]: " << a << " " << b << " " << c << "\n";
    }
    */

    fn(j, edges2.size()) {
      int a, b; ll c;
      a = edges[j].a;
      b = edges[j].b;
      c = edges[j].c;
      if(d[b] < d[a] + c) {
        cycle = true;
        break;
      }
    }

    if(cycle) cout << "-1\n";
    else cout << d[n - 1] << "\n";
  }
  return 0;
}
