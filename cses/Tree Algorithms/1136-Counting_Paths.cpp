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

void dfs(vvi &g, vi &vis, vvi &binary, vi &levels, int p, int n, int l) {
  vis[n] = 1;
  binary[0][n] = p;
  levels[n] = l;
  fn(i, g[n].size())
    if(!vis[g[n][i]]) dfs(g, vis, binary, levels, n, g[n][i], l + 1);
}

void dfs(vvi &g, vi &vis, vvi &binary, int p, int n, vi &prefix) {
  vis[n] = 1;
  fn(i, g[n].size()) {
    if(vis[g[n][i]] == 0) {
      dfs(g, vis, binary, n, g[n][i], prefix);
      prefix[n] += prefix[g[n][i]];
    }
  }
}

#define CHUPALA_MARINKOVIC 30
 
int jump(int a, int k, vvi &binary) {
  fn(i, CHUPALA_MARINKOVIC)
    if((k >> i) & 1) a = binary[i][a];
  return a;
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
    vvi g(n + 1);
    fn(i, n - 1) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    vvi binary(CHUPALA_MARINKOVIC, vi(n + 1, 0));
    vi vis(n + 1, 0);
    vi levels(n + 1, 0);
    dfs(g, vis, binary, levels, 0, 1, 0);
 
    flr(i, 1, CHUPALA_MARINKOVIC) {
      flr(j, 0, n + 1) {
        binary[i][j] = binary[i - 1][binary[i - 1][j]];
      }
    }
    
    vi prefix(n + 1, 0);
    fn(xd, m) {
      int a, b;
      cin >> a >> b;
      prefix[b]++;
      prefix[a]++;
      int lca;
      if(levels[a] < levels[b]) b = jump(b, levels[b] - levels[a], binary);
      else a = jump(a, levels[a] - levels[b], binary);
      if(a == b) lca = a;
      else {
        frle(i, 0, CHUPALA_MARINKOVIC - 1) {
          if(binary[i][a] != binary[i][b]) {
            a = binary[i][a];
            b = binary[i][b];
          }
        }
      
        if(binary[0][a] == 0) lca = 1;
        else lca = binary[0][a];
      }
      prefix[lca]--;
      prefix[binary[0][lca]]--;
    }

    vi vis2(n + 1, 0);
    dfs(g, vis2, binary, 0, 1, prefix); 
    flre(i, 1, n)
      cout << prefix[i] << " ";
    cout << "\n";
  }
  return 0;
}
