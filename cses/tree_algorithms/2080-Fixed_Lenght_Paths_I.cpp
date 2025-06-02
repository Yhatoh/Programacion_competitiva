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

#define MAXNODES 200001
typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

vi g[MAXNODES];
int vis[MAXNODES]; 
int counti[MAXNODES];
int subtrees[MAXNODES];
int max_depth;
int k;
ll ans;

void dfs(int u, int p) {
  subtrees[u] = 1;
  for(int v : g[u]) {
    if(v != p && vis[v] == 0) {
      dfs(v, u);
      subtrees[u] += subtrees[v];
    }
  }
}

void dfs_ans(int u, int p, int depth, bool flag) {
  if(depth > k) return;
  if(flag) {
    counti[depth] += 1;
  } else {
    ans += counti[k - depth];
  }
  max_depth = max(max_depth, depth);
  for(int v : g[u]) {
    if(v != p && vis[v] == 0) {
      dfs_ans(v, u, depth + 1, flag);
    }
  }
}

int centroid(int u, int p, int treesize) {
  for(int v : g[u]) {
    if(v != p && vis[v] == 0) {
      if(subtrees[v] > treesize) 
        return centroid(v, u, treesize);
    }
  }
  return u;
}

void centroid_decompose(int u) {
  dfs(u, -1);
  int centr = centroid(u, -1, subtrees[u] / 2);
  vis[centr] = 1;
  max_depth = 0;
  counti[0] = 1;
  for(int v : g[centr]) {
    if(vis[v] == 0) {
      dfs_ans(v, centr, 1, false);
      dfs_ans(v, centr, 1, true);
    }
  }
  fill(counti, counti + max_depth + 1, 0);
  for(int v : g[centr]) {
    if(vis[v] == 0) {
      centroid_decompose(v);
    }
  }
}

#define debug 1

int main() {
  int t = 1;
  while(t--) {
    int n;
    scanf("%d %d", &n, &k);
    fn(i, n - 1) {
      int a, b;
      scanf("%d %d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }
    centroid_decompose(1);
    printf("%lld\n", ans);
  }
  return 0;
}
