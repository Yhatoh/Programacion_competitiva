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
  os << "]\n";
  return os;
}

void dfs(vvi &g, vi &vis, vi &top, int node, int color) {
  vis[node] = color;
  fn(i, g[node].size()) {
    int v = g[node][i];
    if(vis[v] == 0) dfs(g, vis, top, v, color);
  }
  top.push_back(node);
}

void topsort(vvi &g, vi &vis, vi &top) {
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
    cin >> m >> n;
    vvi g(2 * n);
    vvi gr(2 * n);
    fn(i, m) {
      char x1, x2;
      int a, b;
      cin >> x1 >> a >> x2 >> b;
      a--; b--;
      a *= 2;
      if(x1 == '-') a ^= 1;
      b *= 2;
      if(x2 == '-') b ^= 1;

      int neg_a, neg_b;
      neg_a = a ^ 1;
      neg_b = b ^ 1;

      g[neg_a].push_back(b);
      g[neg_b].push_back(a);
      gr[b].push_back(neg_a);
      gr[a].push_back(neg_b);
    }

    vi vis1(2 * n, 0);
    vi top;

    topsort(g, vis1, top);

    vi vis2(2 * n, 0);
    vi top2;

    int color = 1;
    frle(i, 0, top.size() - 1) {
      if(vis2[top[i]] == 0) {
        dfs(gr, vis2, top2, top[i], color);
        color++;
      }
    }

    vector< bool > assignment(n, false);
    bool check = false;
    for(int i = 0; i < 2 * n; i += 2) {
      if(vis2[i] == vis2[i + 1]) {
        check = true;
        break;
      }
      assignment[i / 2] = vis2[i] > vis2[i + 1];
    }

    if(check) cout << "IMPOSSIBLE\n";
    else {
      fn(i, n) {
        if(assignment[i]) cout << "+ ";
        else cout << "- ";
      }
    }

  }
  return 0;
}
