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
#define feach(x, ds) for(auto &x : ds)
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

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;
typedef long double ld; typedef vector< ld > vld;
typedef vector< vld > vvld; typedef pair< ld, ld > pldld;
typedef vector< pldld > vpldld; typedef vector< vpldld >  vvpldld;

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    string s;
    cin >> s;
    string new_s = "D";
    feach(c, s) {
      if(c == 'L') continue;
      new_s += c;
    }
    new_s += "D";
    vi run_w;
    vi run_d;

    int count = 0;
    bool flag = true;
    feach(c, new_s) {
      if(flag && c == 'D') {
        count++;
      } else if(flag && c == 'W') {
        run_d.push_back(count);
        count = 1;
        flag = false;
      } else if(!flag && c == 'W') {
        count++;
      } else {
        flag = true;
        run_w.push_back(count);
        count = 1;
      }
    }
    if(flag && count > 0) run_d.push_back(count);
    else if(!flag && count > 0) run_w.push_back(count);

    auto wins = [] (int w) { return (w >= 3 ? 2 * w + (w - 2) : w * 2); };

    auto p = [=](int w1, int d, int w2) {
      return wins(w1) + d + wins(w2) <= wins(w1 + w2);
    };

    frle(i, 1, run_d.size() - 2) {
      if(i - 1 < run_w.size() && i < run_w.size()) {
        if(p(run_w[i - 1], run_d[i], run_w[i])) {
          run_d[i] = 0;
          run_w[i - 1] += run_w[i];
          run_w[i] = 0;
        }
      }
    }
    int ans = 0;
    feach(x, run_d) ans += x;
    feach(x, run_w) ans += (x >= 3 ? 2 * x + x - 2 : x * 2);
    cout << ans - 2 << "\n";
  }
  return 0;
}
