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

#define CHUPALA_MARINKOVIC 30

int jump(int a, vll &tons, vvll &binary) {
  frle(i, 0, CHUPALA_MARINKOVIC - 1)
    if(tons[binary[i][a]] > 0) a = binary[i][a];
  return a;
}

int main() {
  int t = 1;
  while(t--) {
    ll q;
    cin >> q;
    vll a(q + 1);
    vll c(q + 1);
    vvll binary(CHUPALA_MARINKOVIC, vll(q + 1, 0));
    cin >> a[0] >> c[0];

    flr(i, 1, q + 1) {
      int op;
      cin >> op;
      if(op == 1) {
        ll p;
        cin >> p >> a[i] >> c[i];
        binary[0][i] = p;
        flr(j, 1, CHUPALA_MARINKOVIC) {
          binary[j][i] = binary[j - 1][binary[j - 1][i]];
        }
      } else {
        ll v; ll w;
        cin >> v >> w;

        ll min_g = 0;
        ll min_t = 0;
        while(a[v] > 0 && w > 0) {
          int parent = jump(v, a, binary); 
          min_t += min(a[parent], w);
          min_g += min(a[parent], w) * c[parent];
          int mini = min(a[parent], w);
          a[parent] -= mini;
          w -= mini;
        }
        cout << min_t << " " << min_g << "\n";
      }
    }
  }
  return 0;
}
