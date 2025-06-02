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

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;

    if(sum % 2) {
      cout << 0 << "\n";
      return 0;
    }
    sum /= 2;
    vector< vector< int > > knapsack(n + 1, vector< int >(sum + 1, 0));

    fn(i, n + 1) knapsack[i][0] = 0;
    fn(i, sum + 1) knapsack[0][i] = 0;
    knapsack[0][0] = 1;

    flre(i, 1, n) {
      flre(j, 0, sum) {
        if(j < i)
          knapsack[i][j] = knapsack[i - 1][j];
        else {
          knapsack[i][j] = (((knapsack[i][j] + knapsack[i - 1][j]) % 1000000007) + knapsack[i - 1][j - i]) % 1000000007;
        }
      }
    }

    cout << knapsack[n - 1][sum] << "\n";
  }
  return 0;
}
