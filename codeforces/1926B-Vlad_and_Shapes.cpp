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
#define feach(x, ds) for(auto &x : ds)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;
typedef long double ld; typedef vector< ld > vld;
typedef vector< vld > vvld; typedef pair< ld, ld > pldld;
typedef vector< pldld > vpldld; typedef vector< vpldld >  vvpldld;

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector< string > vs(n);
    fn(i, n) cin >> vs[i];

    pii row11 = {-1, -1};
    fn(i, n) {
      fn(j, n) {
        if(vs[i][j] == '1') {
          row11 = {i, j};
          break;
        }
      }
      if(row11.first != -1) break;
    }

    pii row1l = {row11.first, row11.second};
    flr(i, row11.second + 1, n) {
      if(vs[row11.first][i] != '1') break;
      row1l.second = i;
    }
    bool flag = true;

    int count1 = 0;
    int count2 = 0;
    fn(i, n) {
      if(row11.first - 1 >= 0 && vs[row11.first - 1][i] == '1') count1++;
      if(row11.first + 1 < n && vs[row11.first + 1][i] == '1') count2++;
    }

    if(count1 > 0 && count1 != row1l.second - row11.second + 1) flag = false;
    if(count2 > 0 && count2 != row1l.second - row11.second + 1) flag = false;
    if(flag) cout << "SQUARE\n";
    else cout << "TRIANGLE\n";
  }
  return 0;
}
