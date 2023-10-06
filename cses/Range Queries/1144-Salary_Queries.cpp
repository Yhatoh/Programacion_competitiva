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

template< typename T, typename T2 >
ostream& operator<<(ostream& os, const map< T, T2 > &m) {
  os << "{";
  for(auto p : m) {
    os << "(" << p.first << "," << p.second << ")";
    os << " ";
  }
  os << "}";
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

template <class T, T merge(T, T)>
struct SegmentTree {
  int N;
  vector<T> ST;
  void build(int n, int l, int r, vector<T> &vs) {
    if(l == r) ST[n] = vs[l];
    else {
      build((n << 1), l, (r + l) / 2, vs);
      build((n << 1) + 1, (r + l) / 2 + 1, r, vs);
      ST[n] = merge(ST[(n << 1)], ST[(n << 1) + 1]);
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
    if(mid < i) return query(mid + 1, r, (n << 1)+1, i, j);
    if(mid >= j) return query(l, mid, (n << 1), i, j);
    return merge(query(l, mid, (n << 1), i, j),
                 query(mid + 1, r, (n << 1) + 1, i, j));
  }
  void update(int pos, T val) {
    update(0, N - 1, 1, pos, val);
  }
  void update(int l, int r, int n, int pos, T val) {
    if(r < pos || pos < l) return;
    if(l == r) ST[n] = val;
    else {
      int mid = (r + l) / 2;
      update(l, mid, (n << 1), pos, val);
      update(mid + 1, r, (n << 1) + 1, pos, val);
      ST[n] = merge(ST[(n << 1)], ST[(n << 1) + 1]);
    }
  }
};

int merge(int a, int b) {
  return a + b;
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
    vi num;
    vi ps(n);
    fn(i, n) {
      cin >> ps[i];
      num.push_back(ps[i]);
    }

    vector< pair< int, pair< int, int > > > queries;
    fn(i, q) {
      char op;
      int a, b;
      cin >> op >> a >> b;
      queries.push_back({(op == '!' ? 1 : 0), {a, b}});
      num.push_back(a);
      num.push_back(b);
    }
    sortv(num);

    map< int, int > compress;
    int code = 0;
    compress[num[0]] = code++;
    flr(i, 1, num.size()) {
      if(num[i - 1] != num[i])
        compress[num[i]] = code++;
    }

    vi new_ps(n);
    fn(i, n) {
      new_ps[i] = compress[ps[i]];
    }
    
    vi arr(code + 1, 0);
    fn(i, n) {
      arr[new_ps[i]]++;
    }

    SegmentTree< int, merge > ST(arr);
    fn(i, q) {
      if(queries[i].first) {
        int pos = queries[i].second.first;
        int val = queries[i].second.second;
        arr[new_ps[pos - 1]]--;
        val = compress[val];
        ST.update(new_ps[pos - 1], arr[new_ps[pos - 1]]);
        new_ps[pos - 1] = val;
        arr[val]++;
        ST.update(val, arr[val]);
      } else {
        cout << ST.query(compress[queries[i].second.first], compress[queries[i].second.second]) << "\n";
      }
    }
  }
  return 0;
}
