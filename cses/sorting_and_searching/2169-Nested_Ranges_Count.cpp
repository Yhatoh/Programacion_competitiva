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

template<class T, T m_(T, T)> struct SegmentTree{
  int n; vector<T> ST;
  SegmentTree(){}
  SegmentTree(vector<T> &a){
    n = a.size(); ST.resize(n << 1);
    for (int i=n;i<(n<<1);i++)ST[i]=a[i-n];
    for (int i=n-1;i>0;i--)ST[i]=m_(ST[i<<1],ST[i<<1|1]);
  }
  void update(int pos, T val){ // replace with val
    ST[pos += n] = val;
    for (pos >>= 1; pos > 0; pos >>= 1)
      ST[pos] = m_(ST[pos<<1], ST[pos<<1|1]);
  }
  T query(int l, int r){ // [l, r]
    T ansL, ansR; bool hasL = 0, hasR = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        ansL=(hasL?m_(ansL,ST[l++]):ST[l++]),hasL=1;
      if (r & 1)
        ansR=(hasR?m_(ST[--r],ansR):ST[--r]),hasR=1;
    }
    if (!hasL) return ansR; if (!hasR) return ansL;
    return m_(ansL, ansR);
  }
};

int merge(int a, int b) {
  return a + b;
}

bool javier(pair< pair< int, int >, int > &a, pair< pair< int, int >, int > &b) {
  if(a.first.first != b.first.first) return a.first.first < b.first.first;
  return a.first.second > b.first.second;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    vector< pair< int, int > > v(n);
    set< int > s;
    fn(i, n) {
      cin >> v[i].first >> v[i].second;
      s.insert(v[i].first);
      s.insert(v[i].second);
    }
    map< int, int > mp;
    int count = 0;
    for(auto x : s)
      mp[x] = count++;

    fn(i, n) {
      v[i].first = mp[v[i].first];
      v[i].second = mp[v[i].second];
    }

    vector< int > cv(count, 0);
    SegmentTree< int, merge > st(cv);
    SegmentTree< int, merge > st2(cv);
    
    vector< int > in(n, 0);
    vector< int > out(n, 0);

    vector< pair< pair< int, int >, int > > now(n);
    fn(i, n) {
      now[i].first.first = v[i].first;
      now[i].first.second = v[i].second;
      now[i].second = i;
    }

    sort(now.begin(), now.end(), javier);

    frle(i, 0, n - 1) {
      out[now[i].second] += st2.query(0, now[i].first.second);
      st2.update(now[i].first.second, st2.query(now[i].first.second, now[i].first.second) + 1);
    }

    fn(i, n) {
      cout << out[i] << " ";
    }
    cout << "\n";
    fn(i, n) {
      in[now[i].second] += st.query(now[i].first.second, count - 1);
      st.update(now[i].first.second, st.query(now[i].first.second, now[i].first.second) + 1);
    }

    fn(i, n) {
      cout << in[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
