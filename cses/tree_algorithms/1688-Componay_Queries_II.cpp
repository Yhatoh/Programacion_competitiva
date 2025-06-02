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
 
#define CHUPALA_MARINKOVIC 30
 
void dfs(vvll &g, vll &dist, int node, int p, int l) {
  dist[node] = l;
  fn(i, g[node].size()) {
    int v = g[node][i];
    if(v != p) dfs(g, dist, v, node, l + 1);
  }
}

int jump(int a, int k, vvll &binary) {
  fn(i, CHUPALA_MARINKOVIC)
    if((k >> i) & 1) a = binary[i][a];
  return a;
}
 
#define debug 1
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, q;
    cin >> n >> q;
    vvll binary(CHUPALA_MARINKOVIC, vll(n + 1, 0));
    vvll g(n + 1);
    fn(i, n - 1) {
      int a;
      cin >> a;
      g[i + 2].push_back(a);
      g[a].push_back(i + 2);
      binary[0][i + 2] = a;
    }
 
    flr(i, 1, CHUPALA_MARINKOVIC) {
      flr(j, 0, n + 1) {
        binary[i][j] = binary[i - 1][binary[i - 1][j]];
      }
    }
 
    vll levels(n + 1, 0);
    dfs(g, levels, 1, 0, 0);
    while(q--) {
      int a, b;
      cin >> a >> b;
      if(levels[a] < levels[b]) b = jump(b, levels[b] - levels[a], binary);
      else a = jump(a, levels[a] - levels[b], binary);

      if(a == b) cout << a << "\n";
      else {
        frle(i, 0, CHUPALA_MARINKOVIC - 1) {
          if(binary[i][a] != binary[i][b]) {
            a = binary[i][a];
            b = binary[i][b];
          }
        }
      
        if(binary[0][a] == 0) cout << 1 << "\n";
        else cout << binary[0][a] << "\n";
      }
    }
  }
  return 0;
}
