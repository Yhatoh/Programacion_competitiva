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

typedef long long ll;

#define MOD 1000000007
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);

  int n, m;
  cin >> n >> m;

  vector< int > values(n);
  fn(i, n) cin >> values[i];

  vector< vector< ll > > dp(2, vector< ll >(m + 1, 0));
  fn(i, m + 1) {
    if(values[0] != 0) dp[0][values[0]] = 1;
    else {
      flr(i, 1, m + 1) {
        dp[0][i] = 1;
      }
    }
  }

  flr(i, 1, n) {
    if(values[i] != 0) {
      fn(i, m + 1) {
        dp[1][i] = 0;
      }
      dp[1][values[i]] = 0;
      dp[1][values[i]] = (dp[1][values[i]] + dp[0][values[i]]) % MOD;
      if(values[i] > 1)
        dp[1][values[i]] = (dp[1][values[i]] + dp[0][values[i] - 1]) % MOD;
      if(values[i] < m)
        dp[1][values[i]] = (dp[1][values[i]] + dp[0][values[i] + 1]) % MOD;
    } else {
      flr(j, 1, m + 1) {
        dp[1][j] = 0;
        dp[1][j] = (dp[1][j] + dp[0][j]) % MOD;
        if(j > 1)
          dp[1][j] = (dp[1][j] + dp[0][j - 1]) % MOD;
        if(j < m)
          dp[1][j] = (dp[1][j] + dp[0][j + 1]) % MOD;
      }
    }
    /*
    cout << "dp[0] =";
    fn(i, m + 1) cout << " " << dp[0][i];
    cout << "\n";
    cout << "dp[1] =";
    fn(i, m + 1) cout << " " << dp[1][i];
    cout << "\n";
    */
    swap(dp[0], dp[1]);
  }

  ll ans = 0;

  flr(i, 1, m + 1) ans = (ans + dp[0][i]) % MOD;

  cout << ans << "\n";
  return 0;
}
