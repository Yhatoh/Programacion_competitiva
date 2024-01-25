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
    ll n, k, d;
    cin >> n >> k >> d;
    vll nums(n, 0);
    bool flag = true;
    fn(i, n) {
      cin >> nums[i];
      flag = flag && nums[i] == 0;
    }
    vll vs(k);
    fn(i, k) cin >> vs[i];

    if(flag) {
      cout << d / 2 << "\n";
      continue;
    }
    int pos = 0;
    ll maxi_score = 0;
    fn(i, n) {
      maxi_score += nums[i] == (i + 1);
    }
    ll a = vs[pos];
    fn(j, a) {
      nums[j]++;
    }
    pos = (pos + 1) % k;
    int day_passed = 1;
    maxi_score += (d - day_passed) / 2;
    flre(i, 2, min((ll) d, 2 * n + n )) {
      int score = 0;
      fn(j, n) {
        score += nums[j] == (j + 1);
      }
      ll a = vs[pos];
      fn(j, a) {
        nums[j]++;
      }
      pos = (pos + 1) % k;
      if(score + (d - i) / 2 > maxi_score) {
        day_passed = i;
        maxi_score = score + (d - day_passed) / 2;
      }
    }
    cout << maxi_score << "\n";
  }
  return 0;
}
