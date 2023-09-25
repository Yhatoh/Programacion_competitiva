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
    int n, m;
    cin >> n >> m;
    vector< ll > a(n);
    vector< ll > b(m);
    fn(i, n) cin >> a[i];
    fn(i, m) cin >> b[i];

    if(n % 2 == 0) {
      ll b_or = 0;
      fn(i, m) b_or |= b[i];

      ll max_v = 0;
      ll min_v = 0;
      fn(i, n) {
        max_v ^= a[i];
        min_v ^= (a[i] | b_or);
      }
      cout << min_v << " " << max_v << "\n";
    } else {
      ll b_or = 0;
      fn(i, m) b_or |= b[i];

      ll max_v = 0;
      ll min_v = 0;
      fn(i, n) {
        min_v ^= a[i];
        max_v ^= (a[i] | b_or);
      }
      cout << min_v << " " << max_v << "\n";

    }
  }
  return 0;
}
