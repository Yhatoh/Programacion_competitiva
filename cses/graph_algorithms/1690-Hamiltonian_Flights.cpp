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

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
  os << "[";
  for(uint64_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if(i != vec.size() - 1)
      os << ", ";
  }
  os << "]\n";
  return os;
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
    vvi g(n, vi(n, 0));
    fn(i, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a][b] += 1;
    }
    
    vvll dp(1 << n, vll(n, 0));

    dp[1][0] = 1;

    for(ll subset = 0; subset < (1 << n); subset++) {
      if(subset != (1 << n) - 1 && ((subset >> (n - 1)) & 1))continue;
      for(int i = 0; i < n; i++) {
        int subset_not_i = subset ^ (1 << i);
        if((subset & (1 << i))) {
          if(subset_not_i) {
            for(int j = 0; j < n; j++) {
              if((subset & (1 << j))) {
                if(g[j][i]) {
                  dp[subset][i] = (dp[subset][i] + dp[subset_not_i][j] * g[j][i]) % 1000000007;
                }
              }
            }
          }
        }
      }
    }

    cout << dp[(1 << n) - 1][n - 1] << "\n";
  }
  return 0;
}
