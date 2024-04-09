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
    ll n;
    cin >> n;
    vll nums(n - 1);
    fn(i, n - 1) cin >> nums[i];

    bool flag = true;
    if(n * (n + 1) / 2 != nums.back()) {
      nums.push_back(n * (n + 1) / 2);
      vll prefix;
      prefix.push_back(nums[0]);
      flr(i, 1, n) {
        prefix.push_back(nums[i] - nums[i - 1]);
      }

      set< ll > check;
      fn(i, n) {
        if(prefix[i] > 0 && prefix[i] <= n) check.insert(prefix[i]);
        else {
          flag = false;
          break;
        }
      }
      if(flag && check.size() != n) flag = false;

      if(flag) cout << "YES\n";
      else cout << "NO\n";
    } else {
      map< ll, ll > count;
      count[nums[0]]++;
      flr(i, 1, n - 1) {
        count[nums[i] - nums[i - 1]]++;
      }

      vll count1;
      feach(p, count) {
        if(p.second > 1) {
          count1.push_back(p.first);
        }
      }
      if(count1.size() > 1) {
        flag = false;
      }

      if(flag && count1.size() == 1) {
        if(count[count1[0]] > 2)
          flag = false;
      } 

      if(flag) {
        vll count0;
        flr(i, 1, n + 1) {
          if(count[i] == 0) {
            count0.push_back(i);
          }
        }
        if(count0.size() != 2) flag = false;
      }
      if(flag) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  return 0;
}
