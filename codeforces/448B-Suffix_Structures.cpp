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

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    string s, t;
    cin >> s >> t;
    int index_s = 0;
    bool erased = true;
    int found = 0;
    fn(i, t.length()) {
      flr(j, index_s, s.length()) {
        if(s[j] == t[i]) {
          index_s = j + 1;
          found++;
          break;
        }
      }
    }
    if(found != t.length()) {
      erased = false;
    }

    if(erased) {
      cout << "automaton\n";
      break;
    }

    map< char, int > ls;
    map< char, int > lt;

    fn(i, s.length()) ls[s[i]]++;
    fn(i, t.length()) lt[t[i]]++;

    bool swap = true;
    for(char a = 'a'; a <= 'z'; a++) {
      if(lt[a] > ls[a]) {
        swap = false;
        break;
      }
      if(lt[a] < ls[a]) {
        erased = true;
      }
    }

    if(swap && erased) cout << "both\n";
    else if(swap) cout << "array\n";
    else cout << "need tree\n";
  }
  return 0;
}
