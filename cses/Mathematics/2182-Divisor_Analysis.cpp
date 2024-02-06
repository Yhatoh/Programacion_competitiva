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

ll expo(ll a, ll b, ll MOD) {
  a %= MOD;
  ll res = 1;
  while(b > 0) {
    if(b % 2) res = (res * a) % MOD;
    a = (a * a) % MOD;
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
    vpll pf(n);
    fn(i, n) cin >> pf[i].first >> pf[i].second;

    ll num = 1;
    fn(i, n) num = (num * (pf[i].second + 1)) % MOD;

    ll sum = 1;
    fn(i, n) {
      sum = (((sum * (expo(pf[i].first, pf[i].second + 1, MOD) - 1)) % MOD) * expo(pf[i].first - 1, MOD - 2, MOD)) % MOD;
    }

    ll prod = 1;
    ll aux = 1;
    fn(i, n) {
      prod = (expo(prod, pf[i].second + 1, MOD) * expo(expo(pf[i].first, (pf[i].second * (pf[i].second + 1) / 2), MOD), aux, MOD) % MOD);
      aux = aux * (pf[i].second + 1) % (MOD - 1);
    }
    cout << num << " " << sum << " " << prod << "\n";
  }
  return 0;
}
