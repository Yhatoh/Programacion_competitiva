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
  while(t--) {
    string s;
    cin >> s;
    if(s.length() == 1) {
      cout << s << "\n";
      return 0;
    }
    string new_s;
    new_s = s[0];
    new_s += s[1];
    flr(i, 2, s.length()) {
      if(s[i] == s[i - 2] && s[i - 1] == s[i]) {
      } else {
        new_s += s[i];
      }
    }

    string final_s = "";
    int i = 0;
    while(i < new_s.length()) {
      if(i + 1 < new_s.length() && new_s[i] == new_s[i + 1]) {
        if(i + 3 < new_s.length()) {
          if(new_s[i + 2] == new_s[i + 3]) {
            final_s += new_s[i];
            final_s += new_s[i + 1];
            final_s += new_s[i + 2];
            i += 4;
          } else {
            final_s += new_s[i];
            final_s += new_s[i + 1];
            i += 2;
          }
        } else {
          final_s += new_s[i];
          final_s += new_s[i + 1];
          i += 2;
        }
      } else {
        final_s += new_s[i];
        i++;
      }
    }
    cout << final_s << "\n";
  }
  return 0;
}
