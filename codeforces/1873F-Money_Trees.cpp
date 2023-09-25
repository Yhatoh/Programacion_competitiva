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

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    vll fs(n);
    vll hs(n);
    fn(i, n) cin >> fs[i];
    fn(i, n) cin >> hs[i];

    int l, r;
    ll total = 0;
    l = 0;
    r = 1;
    bool valid = true;
    while(l < n && fs[l] > k) l++, r++;
    if(l == n) valid = false;
    total += fs[l];
    int len = 1;
    while(r < n) {
      if(hs[r - 1] % hs[r] == 0 && total + fs[r] <= k) {
        total += fs[r];
        r++;
        len = max(len, r - l);
      } else {
        len = max(len, r - l);
        total -= fs[l++];
        if(l == r) {
          total += fs[r];
          r++;
        }
      }
    }
    if(valid)
      cout << max(len, r - l) << "\n";
    else cout << 0 << "\n";
  }
  return 0;
}
