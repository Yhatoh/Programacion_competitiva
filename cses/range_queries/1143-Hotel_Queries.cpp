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
  int select(int k) {
    return select(0, N - 1, 1, k);
  }
  int select(int l, int r, int n, int k) {
    if(l == r) return ST[n].second;
    if(ST[n * 2].first < k) {
      return select((r + l) / 2 + 1, r, n * 2 + 1, k);
    } else {
      return select(l, (r + l) / 2, n * 2, k);
    }
  }
};

pll merge(pll p1, pll p2) {
  if(p1.first > p2.first) {
    return p1;
  }
  return p2;
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
    vpll info(n);
    fn(i, n) {
      cin >> info[i].first;
      info[i].second = i;
    }
    SegmentTree< pll, merge > ST(info);
    fn(i, m) {
      int r;
      cin >> r;
      int res = ST.select(r);
      if(info[res].first >= r) {
        cout << res + 1 << " ";
        ST.update(res, {info[res].first - r, res});
        info[res].first -= r;
      } else {
        cout << 0 << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
