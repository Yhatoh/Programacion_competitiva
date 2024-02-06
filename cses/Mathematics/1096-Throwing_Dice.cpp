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

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

const ll MOD = 1000000007;

vvll mod(vvll a, ll MOD) {
  vvll b(a.size(), vll(a[0].size(), 0));
  fn(i, a.size()) {
    fn(j, a[0].size()) {
      b[i][j] = a[i][j] % MOD;
    }
  }
  return b;
}

vvll mult(vvll a, vvll b, ll MOD) {
  vvll c(a.size(), vll(a[0].size(), 0));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 6; k++) {
        c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
      }
    }
  }
  return c;
}
        

vvll expo(vvll &a, ll b, ll MOD) {
  a = mod(a, MOD);
  vvll res(a.size(), vll(a[0].size(), 0));
  fn(i, res.size()) res[i][i] = 1;

  while(b > 0) {
    if(b % 2) res = mod(mult(res, a, MOD), MOD);
    a = mod(mult(a, a, MOD), MOD);
    b /= 2;
  }
  return res;
}

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    ll n;
    cin >> n;
    vvll base(6, vll(6, 0));
    fn(i, 6) base[0][i] = 1;
    fn(i, 5) base[i + 1][i] = 1;
    cout << expo(base, n, MOD)[0][0] << "\n";
  }
  return 0;
}
