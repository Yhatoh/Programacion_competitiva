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

void valids(ll curr, ll i, ll next, vector< ll > &masks, ll n) {
  if(i == n) {
    masks.push_back(next);
    return;
  }

  if(curr & (1 << i)) valids(curr, i + 1, next, masks, n);
  if(i < n - 1) {
    if((curr & (1 << i)) == 0 && (curr & (1 << (i + 1))) == 0) {
      valids(curr, i + 2, next, masks, n);
    }
  }
  if((curr & (1 << i)) == 0) valids(curr, i + 1, next | (1 << i), masks, n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  
  ll n, m;
  cin >> n >> m;

  vector< vector< ll > > dp(m + 1, vector< ll >(1 << n, 0));
  dp[0][0] = 1;
  flr(i, 1, m + 1) {
    flr(j, 0, 1 << n) {
      vector< ll > masks;
      valids(j, 0, 0, masks, n);
      for(ll x : masks) {
        dp[i][x] = (dp[i][x] + dp[i - 1][j]) % 1000000007;
      }
    }
  }

  cout << dp[m][0] << "\n";
  return 0;
}
