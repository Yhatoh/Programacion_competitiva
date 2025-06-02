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
 
  int n;
  cin >> n;
  vector< int > vec(n);
  fn(i, n) cin >> vec[i];
  sortv(vec);
 
  vector< vector< int > > dp(2, vector< int >(1000001, 0));
  dp[0][0] = 1;
 
  fn(i, n) {
    fn(j, 1000001) {
      dp[1][j] = 0;
      dp[1][j] |= dp[0][j] | (j >= vec[i] ? dp[0][j - vec[i]] : 0);
    }
    /*
    cout << "dp[0] =";
    fn(i, 1000001) cout << " " << dp[0][i];
    cout << "\n";
    cout << "dp[1] =";
    fn(i, 1000001) cout << " " << dp[1][i];
    cout << "\n";
    */
    swap(dp[0], dp[1]);
  }
 
  int size = 0;
  flr(i, 1, 1000001) {
    size += dp[0][i];
  }
 
  cout << size << "\n";
  flr(i, 1, 1000001) {
    if(dp[0][i])
      cout << i << " ";
  }
  cout << "\n";
  return 0;
}
