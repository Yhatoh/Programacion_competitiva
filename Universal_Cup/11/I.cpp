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
    int n, m;
    cin >> n >> m;
    vpii condition(m);
    fn(i, m) {
      cin >> condition[i].first >> condition[i].second;
    }
    sortv(condition);

    int prev_value = 0;
    int prev_op = 0;
    bool flag = true;
    fn(i, m) {
      if(condition[i].first == prev_op) {
        if(condition[i].second != prev_value) {
          flag = false;
          break;
        }
      } else {
        if(condition[i].second > prev_value) {
          if(condition[i].second - prev_value == condition[i].first - prev_op) {
            // se puede
          } else if(condition[i].second <= condition[i].first - prev_op) {
            // se puede
          } else {
            flag = false;
            break;
          }
        } else {
          if(condition[i].second < condition[i].first - prev_op) {
            // se puede
          } else {
            flag = false;
            break;
          }
        }
      }
      prev_op = condition[i].first;
      prev_value = condition[i].second;
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
