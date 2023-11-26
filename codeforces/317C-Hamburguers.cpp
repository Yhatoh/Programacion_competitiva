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

bool f(ll cb, ll cs, ll cc, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll mid, ll money) {
  return (max(0LL, cb * mid - nb) * pb + max(0LL, cs * mid - ns) * ps + max(0LL, cc * mid - nc) * pc) <= money;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    string s;
    cin >> s;
    ll cb, cs, cc;
    cb = cs = cc = 0;
    fn(i, s.length()) {
      if(s[i] == 'B') cb++;
      else if(s[i] == 'S') cs++;
      else cc++;
    }

    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll money;
    cin >> money;

    ll l = 0;
    ll r = 10000000000000;
    ll ans = 0;
    while(l < r) {
      ll mid = (r + l) / 2;
      if(f(cb, cs, cc, nb, ns, nc, pb, ps, pc, mid, money)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
