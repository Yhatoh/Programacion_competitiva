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
#define feach(x, e) for(auto &x : e)
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
    vi nums(n);
    fn(i, n) cin >> nums[i];

    int negs = 0;
    int mini = -1000000000;
    int minii = -1;
    int zero = 0;
    fn(i, n) {
      zero = zero || (nums[i] == 0);
      if(nums[i] < 0 && mini < nums[i]) {
        mini = max(mini, nums[i]);
        minii = i;
      }

      negs += nums[i] < 0;
    }

    if(zero) {
      cout << 0 << "\n";
    } else if(negs == 0) {
      cout << 1 << "\n";
      cout << 0 + 1 << " " << 0 << "\n";
    } else if(negs % 2 == 1 ) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
      cout << minii + 1 << " " << 0 << "\n";
    }
  }
  return 0;
}
