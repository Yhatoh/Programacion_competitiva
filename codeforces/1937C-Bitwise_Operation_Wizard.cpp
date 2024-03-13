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
  int t = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int maxi_i = 0;
    flr(i, 1, n) {
      cout << "? " << i << " " << i << " " << maxi_i << " " << maxi_i << endl;
      char c;
      cin >> c;
      if(c == '>') maxi_i = i;
    }

    vector< int > cands;
    int maxi_j = 0;
    cands.push_back(maxi_j);
    flr(i, 1, n) {
      cout << "? " << i << " " << maxi_i << " "  << maxi_i << " " << maxi_j << endl;
      char c;
      cin >> c;
      if(c == '>') { 
        maxi_j = i;
        cands.clear();
        cands.push_back(i);
      } else if(c == '=') {
        cands.push_back(i);
      }
    }

    int mini_i = 0;
    flr(i,1, cands.size()) {
      cout << "? " << cands[i] << " " << cands[i] << " " << cands[mini_i] << " " << cands[mini_i] << endl;
      char c;
      cin >> c;
      if(c == '<') mini_i = i;
    }

    cout << "! " << maxi_i << " " << cands[mini_i] << endl;

  }
  return 0;
}
