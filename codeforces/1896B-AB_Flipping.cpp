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
    int n;
    cin >> n;
    string s; cin >> s;

    int amount_a = 0;
    char prev_l = ' ';
    int amount_b = 0;
    int ans = 0;
    int groups = 0;
    fn(i, n) {
      if(prev_l == ' ' && s[i] == 'B') continue;
      else if(prev_l == 'A' && s[i] == 'A') {
        amount_a++;
      } else if(prev_l == 'A' && s[i] == 'B') {
        amount_b++;
      } else if(prev_l == 'B' && s[i] == 'B') {
        amount_b++;
      } else if(prev_l == 'B' && s[i] == 'A') {
        ans += amount_b + amount_a - 1;
        amount_a = 1;
        amount_b = 0;
        groups++;
      }
      prev_l = s[i];
    }
    if(prev_l == 'B') {
      ans += amount_b + amount_a - 1;
      groups++;
    }
    cout << ans + groups << "\n";


  }
  return 0;
}
