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
    vi nums(n);
    fn(i, n) cin >> nums[i];

    map< int, vi > cants;
    fn(i, n) cants[nums[i]].push_back(i);

    bool check = true;
    if(cants.size() == 1) check = false;
    else {
      int at_least = 0;
      for(auto itr = cants.begin(); itr != cants.end(); itr++) {
        if(itr->second.size() > 1) at_least++;
      }
      if(at_least < 2) check = false;
    }

    if(!check) cout << -1 << "\n";
    else {
      vi res(n);
      int at_least = 0;
      for(auto itr = cants.begin(); itr != cants.end(); itr++) {
        if(at_least == 0 && itr->second.size() > 1) {
          res[itr->second[0]] = 1;
          flr(i, 1, itr->second.size()) {
            res[itr->second[i]] = 2;
          }
          at_least++;
        } else if(at_least == 1 && itr->second.size() > 1) {
          res[itr->second[0]] = 2;
          flr(i, 1, itr->second.size()) {
            res[itr->second[i]] = 3;
          }
        } else {
          flr(i, 0, itr->second.size()) {
            res[itr->second[i]] = 3;
          }
        }
      }
      fn(i, n) cout << res[i] << " ";
      cout << "\n";
    }

  }
  return 0;
}
