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
  cin >> t;
  while(t--) {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vvll grid(n, vll(m, 0));
    fn(i, n) {
      fn(j, m) {
        cin >> grid[i][j];
      }
    }

    vll rows(n, 0);
    fn(i, n) {
      if(d >= m) rows[i] = 2;
      else {
        map< ll, ll > mp;
        vll ans_row(m, 0);
        ans_row[0] = 1;
        mp[1]++;
        flr(j, 1, m) {
          if(j - 1 > d) {
            mp[ans_row[j - 1 - d - 1]]--;
            if(mp[ans_row[j - 1 - d - 1]] == 0) mp.erase(ans_row[j - 1 - d - 1]);
          }
          ans_row[j] = mp.begin()->first + grid[i][j] + 1;
          mp[ans_row[j]]++;
        }
        rows[i] = ans_row[m - 1];
      }
    }

    ll ans = 10000000000000;
    fn(i, n - k + 1) {
      ll row = 0;
      flr(j, i, i + k) {
        row += rows[j];
      }
      ans = min(ans, row);
    }
    cout << ans << "\n";
  }
  return 0;
}
