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

template <class T, T merge(T, T)>
struct SegmentTree {
  int N;
  vector<T> ST;
  void build(int n, int l, int r, vector<T> &vs) {
    if(l == r) ST[n] = vs[l];
    else {
      build(n * 2, l, (r + l) / 2, vs);
      build(n * 2 + 1, (r + l) / 2 + 1, r, vs);
      ST[n] = merge(ST[n * 2], ST[n * 2 + 1]);
    }
  }
  SegmentTree() {}
  SegmentTree(vector<T> &vs) {
    N = vs.size();
    ST.resize(4 * N + 3);
    build(1, 0, N - 1, vs);
  }
  T query(int i, int j) {
    return query(0, N - 1, 1, i, j);
  }
  T query(int l, int r, int n, int i, int j) {
    if(l >= i && r <= j) return ST[n];
    int mid = (r + l) / 2;
    if(mid < i) return query(mid + 1, r, n*2+1, i, j);
    if(mid >= j) return query(l, mid, n*2, i, j);
    return merge(query(l, mid, n * 2, i, j),
                 query(mid + 1, r, n * 2 + 1, i, j));
  }
  void update(int pos, T val) {
    update(0, N - 1, 1, pos, val);
  }
  void update(int l, int r, int n, int pos, T val) {
    if(r < pos || pos < l) return;
    if(l == r) ST[n] = val;
    else {
      int mid = (r + l) / 2;
      update(l, mid, n * 2, pos, val);
      update(mid + 1, r, n * 2 + 1, pos, val);
      ST[n] = merge(ST[n * 2], ST[n * 2 + 1]);
    }
  }
};

ll merge(ll a, ll b) { return a + b; }

void dfs(vvll &g, vll &values, vll &vis, vll &start, vll &end, vll &flatten, int &level, int n) {
  vis[n] = 1;
  start[n] = ++level;
  flatten[level] += values[n];
  fn(i, g[n].size()) {
    if(vis[g[n][i]] == 0) {
      dfs(g, values, vis, start, end, flatten, level, g[n][i]);
    }
  }
  end[n] = level;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, q;
    cin >> n >> q;
    vvll g(n);
    vll values(n);
    fn(i, n) cin >> values[i];

    fn(i, n - 1) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vll vis(n, 0);
    vll start(n, 0);
    vll end(n, 0);
    vll flatten(n + 1, 0);
    int level = 0;
    dfs(g, values, vis, start, end, flatten, level, 0);
    SegmentTree< ll, merge > ST(flatten);
    fn(i, q) {
      int op;
      cin >> op;
      if(op == 1) {
        ll s, x;
        cin >> s >> x;
        s--;
        values[s] = x;
        ST.update(start[s], values[s]);
      } else {
        ll s;
        cin >> s;
        s--;
        cout << ST.query(start[s], end[s]) << "\n";
      }
    }
  }
  return 0;
}
