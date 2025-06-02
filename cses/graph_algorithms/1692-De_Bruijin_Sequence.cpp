/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define dbg(var) cout << #var << " = " << var << "\n";
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
ostream& operator<<(ostream& os, const set< T > &m) {
  os << "{";
  for(auto p : m) {
    os << p << ", ";
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

void generate(string s, map< int, string > &options, map< string, int > &to_node, int &index, int size) {
  if(size == s.length()) {
    options[index] = s;
    to_node[s] = index;
    index++;
    return;
  }

  generate(s + "0", options, to_node, index, size);
  generate(s + "1", options, to_node, index, size);
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
    if(n == 1) {
      cout << "01\n";
      return 0;
    }
    map< int, string > options;
    map< string, int > to_node;
    int index = 0;
    generate("", options, to_node, index, (n - 1));

    vector< set< pair< int, string > > > g(1 << (n - 1));
    fn(i, 1 << (n - 1)) {
      string opt = options[i];
      string next_1 = opt.substr(1) + "1";
      string next_0 = opt.substr(1) + "0";
      g[i].insert({to_node[next_1], "1"});
      g[i].insert({to_node[next_0], "0"});
    }

    stack< pair< int, string > > st;
    st.push({0, "#"});
    vi vis(1 << (n - 1), 0);
    string ans = "";
    while(!st.empty()) {
      int now = st.top().first;
      string c = st.top().second;
      vis[now] = 1;
      if(g[now].size() == 0) {
        if(c != "#")
          ans += c;
        st.pop();
      } else {
        int next_n = g[now].begin()->first;
        string next_c = g[now].begin()->second;
        g[now].erase({next_n, next_c});
        st.push({next_n, next_c});
      }
    }
    cout << ans + options[0] << "\n";
  }
  return 0;
}
