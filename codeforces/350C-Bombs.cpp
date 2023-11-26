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

struct moves {
  int type, k;
  char mov;
  moves(int _type, int _k, char _mov) : type(_type), k(_k), mov(_mov) {}
};

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    ll n;
    cin >> n;
    vector< pair< ll, pair< ll, ll > > > bombs(n);
    fn(i, n) {
      ll x, y;
      cin >> x >> y;

      bombs[i].first = (x < 0 ? -1 * x : x) + (y < 0 ? -1 * y : y);
      bombs[i].second.first = x;
      bombs[i].second.second = y;
    }

    sortv(bombs);

    vector< moves > oper;
    fn(i, n) {
      ll x, y;
      x = bombs[i].second.first;
      y = bombs[i].second.second;

      if(x != 0) {
        if(x < 0) {
          oper.push_back(moves(1, -1 * x, 'L'));
        } else {
          oper.push_back(moves(1, x, 'R'));
        }
      }

      if(y != 0) {
        if(y < 0) {
          oper.push_back(moves(1, -1 * y, 'D'));
        } else {
          oper.push_back(moves(1, y, 'U'));
        }
      }

      oper.push_back(moves(2, 0, 'A'));

      if(x != 0) {
        if(x < 0) {
          oper.push_back(moves(1, -1 * x, 'R'));
        } else {
          oper.push_back(moves(1, x, 'L'));
        }
      }

      if(y != 0) {
        if(y < 0) {
          oper.push_back(moves(1, -1 * y, 'U'));
        } else {
          oper.push_back(moves(1, y, 'D'));
        }
      }
      
      oper.push_back(moves(3, 0, 'A'));
    }

    cout << oper.size() << "\n";
    fn(i, oper.size()) {
      if(oper[i].type == 1) {
        cout << oper[i].type << " " << oper[i].k << " " << oper[i].mov << "\n";
      } else {
        cout << oper[i].type << "\n";
      }
    }
  }
  return 0;
}
