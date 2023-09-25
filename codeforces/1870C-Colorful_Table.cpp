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
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector< int > v(n);
    set< int > values;
    fn(i, n) {
      cin >> v[i];
      values.insert(v[i]);
    }

    vector< int > max_l(n);
    vector< int > max_r(n);
    max_l[0] = v[0];
    flr(i, 1, n) {
      if(max_l[i - 1] > v[i]) {
        max_l[i] = max_l[i - 1];
      } else {
        max_l[i] = v[i];
      }
    }
    max_r[n - 1] = v[n - 1];
    frle(i, 0, n - 2) {
      if(max_r[i + 1] > v[i]) {
        max_r[i] = max_r[i + 1];
      } else {
        max_r[i] = v[i];
      }
    }

    /*
    fn(i, n) cout << max_l[i] << " ";
    cout << "\n";
    fn(i, n) cout << max_r[i] << " ";
    cout << "\n";
    */
    reverse(max_r.begin(), max_r.end());
    flre(i, 1, k) {
      auto itr = lower_bound(max_l.begin(), max_l.end(), i);
      auto itr2 = lower_bound(max_r.begin(), max_r.end(), i);
      if(values.find(i) != values.end()) cout << 2 * ((n - (itr2 - max_r.begin())) - (itr - max_l.begin())) << " ";
      else cout << 0 << " ";
    }
    cout << "\n";
  }
  return 0;
}
