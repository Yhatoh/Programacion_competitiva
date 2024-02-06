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

#define MAXI 1000001

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    vll primes(n);
    vll cnt(MAXI, 0);

    fn(i, n) {
      cin >> primes[i];
      cnt[primes[i]]++;
    }

    vll lpf(MAXI, 0);
    flr(i, 2, MAXI) {
      if(!lpf[i]) {
        for(int j = i; j < MAXI; j += i) {
          if(!lpf[j]) lpf[j] = i;
        }
      }
    }

    vll mobius(MAXI, 0);
    flr(i, 1, MAXI) {
      if(i == 1) mobius[i] = 1;
      else {
        if(lpf[i / lpf[i]] == lpf[i]) mobius[i] = 0;
        else mobius[i] = -1 * mobius[i / lpf[i]];
      }
    }
    ll ans = 0;
    flr(i, 1, MAXI) {
      if(mobius[i] == 0) continue;
      ll d = 0;
      for(int j = i; j < MAXI; j += i) {
        d += cnt[j];
      }
      ans += (d * (d - 1)) / 2 * mobius[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
