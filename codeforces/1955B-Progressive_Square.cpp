/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <algorithm>
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
    ll n, c, d;
    cin >> n >> c >> d;
    vll nums(n * n);
    fn(i, n * n) cin >> nums[i];

    ll a = *min_element(nums.begin(), nums.end());
    map< ll, ll > freq_nums;
    feach(x, nums) freq_nums[x]++;

    vvll matrix(n, vll(n, 0));
    matrix[0][0] = a;
    fn(i, n) {
      fn(j, n) {
        if(i + 1 < n) matrix[i + 1][j] = matrix[i][j] + c;
        if(j + 1 < n) matrix[i][j + 1] = matrix[i][j] + d;
      }
    }

    bool flag = true;
    fn(i, n) {
      fn(j, n) {
        if(freq_nums[matrix[i][j]] == 0) {
          flag = false;
          break;
        } else {
          freq_nums[matrix[i][j]]--;
        }
      }
      if(!flag) break;
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
