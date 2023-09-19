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

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector< int > v(n);
    fn(i, n) cin >> v[i];

    multiset< int > s;
    set< int > s2;
    ll l = 0;
    ll r = 0;
    ll ans = 0;
    while(l < n) {
      while(r < n && (int) s2.size() <= k) {
        if((int)s2.size() == k && s.find(v[r]) == s.end()) {
          break;
        }
        s.insert(v[r++]);
        s2.insert(v[r - 1]);
      }

      ans += (r - l);
      s.erase(s.find(v[l++]));
      if(s.find(v[l - 1]) == s.end()) s2.erase(v[l - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}