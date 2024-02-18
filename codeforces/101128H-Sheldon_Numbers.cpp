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
  while(t--) {
    set< string > nums;
    flr(i, 1, 64 + 1) {
      flr(j, 0, 64 + 1) {
        for(int k = 0; i + k * (i + j) <= 64; k++) {
          string s = "";
          fn(l, i) s += "1";
          fn(l, k) {
            fn(m, j) s += "0";
            fn(n, i) s += "1";
          }
          while(s.length() <= 64) s = "0" + s;
          nums.insert(s);
        }
        for(int k = 0; i + k * (i + j) + j <= 64; k++) {
          string s = "";
          fn(l, i) s += "1";
          fn(l, k) {
            fn(m, j) s += "0";
            fn(n, i) s += "1";
          }
          fn(l, j) s += "0";
          while(s.length() <= 64) s = "0" + s;
          nums.insert(s);
        }
      }
    }

    ll x, y;
    cin >> x >> y;
    string bin_x = "";
    while(x > 0) {
      if(x & 1) bin_x += "1";
      else bin_x += "0";
      x /= 2;
    }
    reverse(bin_x.begin(), bin_x.end());
    while(bin_x.length() <= 64) bin_x = "0" + bin_x;
    string bin_y = "";
    while(y > 0) {
      if(y & 1) bin_y += "1";
      else bin_y += "0";
      y /= 2;
    }
    reverse(bin_y.begin(), bin_y.end());
    while(bin_y.length() <= 64) bin_y = "0" + bin_y;
    auto itr_x = nums.lower_bound(bin_x);
    auto itr_y = nums.lower_bound(bin_y);
    ll count = 0;
    while(itr_x != itr_y) {
      count++;
      itr_x++;
    }
    count += (bin_y == *itr_y ? 1 : 0);
    cout << count << "\n";
  }
  return 0;
}
