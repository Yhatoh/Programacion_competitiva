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
    int n, m, q;
    cin >> n >> m >> q;
    vector< vector< ll > > d(n, vector< ll >(n, 100000000000000));
    fn(i, m) {
      ll a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      d[a][b] = min(d[a][b], c);
      d[b][a] = min(d[a][b], c);
    }

    fn(i, n) d[i][i] = 0;

    fn(k, n)
      fn(i, n)
        fn(j, n)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    while(q--) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      cout << (d[a][b] != 100000000000000 ? d[a][b] : -1) << "\n";
    }
  }
  return 0;
}
