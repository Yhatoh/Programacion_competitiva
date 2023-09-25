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
    vector< string > ring(10);
    fn(i, 10) cin >> ring[i];

    int sum = 0;
    fn(i, 10) {
      fn(j, 10) {
        if(ring[i][j] == 'X') {
          if(i == 0 || j == 0 || i == 9 || j == 9) sum += 1;
          else if((i == 1 && j >= 1 && j <= 8) ||
                  (j == 1 && i >= 1 && i <= 8) ||
                  (i == 8 && j >= 1 && j <= 8) ||
                  (j == 8 && i >= 1 && i <= 8)) sum += 2;
          else if((i == 2 && j >= 2 && j <= 7) ||
                  (j == 2 && i >= 2 && i <= 7) ||
                  (i == 7 && j >= 2 && j <= 7) ||
                  (j == 7 && i >= 2 && i <= 7)) sum += 3;
          else if((i == 3 && j >= 3 && j <= 6) ||
                  (j == 3 && i >= 3 && i <= 6) ||
                  (i == 6 && j >= 3 && j <= 6) ||
                  (j == 6 && i >= 3 && i <= 6)) sum += 4;
          else sum += 5;
        }
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
