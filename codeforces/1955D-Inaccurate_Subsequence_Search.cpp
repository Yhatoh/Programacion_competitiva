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
    int n, m, k;
    cin >> n >> m >> k;
    vi nums(n);
    fn(i, n) {
      cin >> nums[i];
    }

    vi b(m);
    fn(i, m) cin >> b[i];

    map< ll, int > count_b;
    fn(i, m) count_b[b[i]]++;

    int ans = 0;
    int l = 0;
    int r = 0;
    int match = 0;

    map< ll, int > incase;
    while(r < n) {
      if(r < m) {
        auto p = count_b.find(nums[r]);
        if(p != count_b.end()) {
          if(p->second != 0) {
            match++;
            p->second--;
          } else {
            incase[nums[r]]++;
          }
        }
        r++;
      } else {
        ans += (match >= k);
        auto l_ = count_b.find(nums[l]);
        if(l_ != count_b.end()) {
          l_->second++;
          match--;
          auto aux_l = incase.find(nums[l]);
          if(aux_l != incase.end() && aux_l->second > 0) {
            l_->second--;
            match++;
            aux_l->second--;
          }
        }
        auto p = count_b.find(nums[r]);
        if(p != count_b.end()) {
          if(p->second != 0) {
            match++;
            p->second--;
          } else {
            incase[nums[r]]++;
          }
        }
        l++; r++;
      }
    }
    ans += (match >= k);
    cout << ans << "\n";
  }
  return 0;
}
