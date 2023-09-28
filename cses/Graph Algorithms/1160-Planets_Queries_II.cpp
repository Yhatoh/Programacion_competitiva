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

template< typename T, typename T2 >
ostream& operator<<(ostream& os, const pair< T, T2 > &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

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

int dfs(vvi &g, vi &cycles, vi &vis, int node, int &color) {
  vis[node] = 2;

  fn(i, g[node].size()) {
    int v = g[node][i];
    if(vis[v] == 0) {
      int ret = dfs(g, cycles, vis, v, color);
      if(cycles[node] == 0) {
        cycles[node] = ret;
        vis[node] = 1;
        return ret;
      } else {
        vis[node] = 1;
        return 0;
      }
    } else if(vis[v] == 2) {
      cycles[node] = color++;
      cycles[v] = cycles[node];
      vis[node] = 1;
      if(node == v) return 0;
      return cycles[node];
    }
  }
  
  vis[node] = 1;
  
  return 0;
}

void gbs(vvi &g, vi &cycles, vi &dist, int node) {
  fn(i, g[node].size()) {
    int v = g[node][i];
    if(cycles[v] == 0) {
      if(dist[v] != 0) {
        dist[node] = dist[v] + 1;
        return;
      }
      gbs(g, cycles, dist, v);
      dist[node] = dist[v] + 1;
      return;
    } else if(cycles[node] == 0) {
      dist[node] = 1;
      return;
    }
  }

  return;
}

void cfs(vvi &g, vpii &dist, int node, int depth) {
  dist[node].first = depth;
  fn(i, g[node].size()) {
    int v = g[node][i];
    if(dist[v].first == -1) {
      cfs(g, dist, v, depth + 1);
      dist[node].second = dist[v].second;
    } else {
      dist[node].second = dist[node].first;
    }
  }
}

#define CHUPALA_MARINKOVIC 30

int jump(int a, int k, vvll &binary) {
  fn(i, CHUPALA_MARINKOVIC)
    if((k >> i) & 1) a = binary[i][a];
  return a;
}

int main() {
#ifndef DEBUG
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    int n, q;
    cin >> n >> q;
    vvi g(n);
    vvll binary(CHUPALA_MARINKOVIC, vll(n, 0));
    fn(i, n) {
      int a;
      cin >> a;
      a--;
      g[i].push_back(a);
      binary[0][i] = a;
    }

    flr(i, 1, CHUPALA_MARINKOVIC) {
      flr(j, 0, n) {
        binary[i][j] = binary[i - 1][binary[i - 1][j]];
      }
    }

    vi cycles(n, 0);
    vi vis(n, 0);
    int color = 1;
    fn(i, n)
      if(vis[i] == 0)
        dfs(g, cycles, vis, i, color);
    
    vi dist(n, 0);
    fn(i, n)
      gbs(g, cycles, dist, i);

    vpii distesp(n, {-1, -1});
    fn(i, n)
      if(cycles[i] != 0 && distesp[i].first == -1)
        cfs(g, distesp, i, 0);

    while(q--) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      if(a == b) cout << 0 << "\n";
      else if(cycles[a] == 0 && cycles[b] == 0) {
        if(dist[a] >= dist[b]) {
          if(jump(a, dist[a] - dist[b], binary) == b)
            cout << dist[a] - dist[b] << "\n";
          else
            cout << "-1\n";
        } else {
          cout << "-1\n";
        }
      } else if(cycles[a] != 0 && cycles[b] != 0) {
        if(cycles[a] != cycles[b])
          cout << "-1\n";
        else {
          if(distesp[a].first < distesp[b].first)
            cout << distesp[b].first - distesp[a].first << "\n";
          else 
            cout << distesp[a].second - distesp[a].first + distesp[b].first + 1 << "\n";
        }
      } else if(cycles[b] != 0) {
        int node = jump(a, dist[a], binary);
        if(cycles[node] != cycles[b]) cout << "-1\n";
        else {
          if(distesp[node].first <= distesp[b].first)
            cout << distesp[b].first - distesp[node].first + dist[a] << "\n";
          else 
            cout << distesp[node].second - distesp[node].first + distesp[b].first + 1 + dist[a] << "\n";
        }
      } else {
        cout << "-1\n";
      }
    }
  }
  return 0;
}
