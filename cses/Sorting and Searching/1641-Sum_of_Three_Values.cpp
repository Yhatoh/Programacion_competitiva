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
    ll n, x;
    cin >> n >> x;
    vector< pair< ll, ll > > v(n);
    fn(i, n) {
      cin >> v[i].first;
      v[i].second = i + 1;
    }

    sortv(v);
    bool flag = false;
    vector< ll > ans(3);
    fn(i, n) {
      if(v[i].first > x) continue;
      ll l = 0;
      ll r = n - 1;
      while(l < r) {
        if(l == i) {
          l++;
          continue;
        }
        if(r == i) {
          r--;
          continue;
        }
        if(v[i].first + v[l].first + v[r].first == x) {
          ans[0] = v[i].second;
          ans[1] = v[l].second;
          ans[2] = v[r].second;
          flag = true;
          break;
        }
        if(v[i].first + v[l].first + v[r].first < x) {
          l++;
          continue;
        }
        if(v[i].first + v[l].first + v[r].first > x) {
          r--;
          continue;
        }
      }
      if(flag) break;
    }
    if(flag) {
      cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
  return 0;
}
