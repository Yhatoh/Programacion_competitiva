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

char flip(char x) {
  if(x == 'U') return 'D';
  return 'U';
}

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
    string s;
    cin >> s;
    bool turn = 1;
    while(s.size()) {
      int pos = -1;
      fn(i, s.size()) {
        if(i > 0 && s[i] == s[i - 1] && s[i] == s[(i + 1) % s.size()] && s[i] == 'U') pos = i;
        else if(s[i] == s[s.size() - 1] && s[i] == s[(i + 1) % s.size()] && s[i] == 'U') pos = i;
      }

      if(pos == -1) {
        fn(i, s.size()) {
          if(i > 0 && (s[i] == s[i - 1] || s[i] == s[(i + 1) % s.size()]) && s[i] == 'U') pos = i;
          else if((s[i] == s[s.size() - 1] || s[i] == s[(i + 1) % s.size()]) && s[i] == 'U') pos = i;
        }
        if(pos == -1) {
          fn(i, s.size()) {
            if(s[i] == 'U') pos = i;
          }
          if(pos == -1) {
            break;
          }
        }
      }
      if(pos > 0) s[pos - 1] = flip(s[pos - 1]);
      else s[s.size() - 1] = flip(s[s.size() - 1]);
      s[(pos + 1) % s.size()] = flip(s[(pos + 1) % s.size()]);
      s.erase(s.begin() + pos);
      turn = !turn;
    }
    if(turn) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
