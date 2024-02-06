/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define feach(x, ds) for(auto &x : ds)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

typedef long double ld; typedef vector< ld > vld; typedef vector< vld >  vvld;

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(6);
#endif
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    vpii dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector< vvld > dp(n + 1, vvld(8, vld(8, 0)));
    vvld ans(8, vld(8, 1));
    fn(i, 8) {
      fn(j, 8) {
        fn(k, n + 1) {
          fn(l, 8) {
            fn(m, 8) {
              dp[k][l][m] = 0;
            }
          }
        }
        dp[0][i][j] = 1;
        flr(k, 1, n + 1) {
          fn(l, 8) {
            fn(m, 8) {
              ld valid_dirs = 0;
              fn(i, 4) {
                ll nl = l + dirs[i].first; ll nm = m + dirs[i].second;
                if(nl >= 0 && nl < 8 && nm >= 0 && nm < 8) valid_dirs++;
              }
              fn(i, 4) {
                ll nl = l + dirs[i].first; ll nm = m + dirs[i].second;
                if(nl >= 0 && nl < 8 && nm >= 0 && nm < 8)
                  dp[k][nl][nm] += dp[k - 1][l][m] / valid_dirs;
              }
            }
          }
        }
        fn(l, 8) {
          fn(m, 8) {
            ans[l][m] *= (1 - dp[n][l][m]);
          }
        }
      }
    }
    ld expected = 0;
    fn(i, 8) {
      fn(j, 8) {
        expected += ans[i][j];
      }
    }
    cout << expected << "\n";
  }
  return 0;
}
