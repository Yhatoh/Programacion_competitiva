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

struct Update {
  ll type, x1, y1, x2, y2;
  char col;
  Update() {}
  Update(ll type_, ll x1_, ll y1_, ll x2_, ll y2_, char col_) :
    type(type_), x1(x1_), y1(y1_), x2(x2_), y2(y2_), col(col_) {}
};

bool check(ll i, ll j, ll x, ll y, ll r) {
  return (x - i) * (x - i) + (y - j) * (y - j) <= r * r;
}

bool check(ll i, ll j, ll x1, ll y1, ll x2, ll y2) {
  return (x1 <= i && i <= x2) && (y1 <= j && j <= y2);
}

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    vector< Update > ups;
    fn(i, n) {
      string type;
      cin >> type;
      if(type == "Circle") {
        ll type_ = 0;
        ll x, y, r;
        cin >> x >> y >> r;
        char c;
        cin >> c;
        ups.push_back(Update(type_, x, y, r, -1, c));
      } else if(type == "Rectangle") {
        ll type_ = 1;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        char c;
        cin >> c;
        ups.push_back(Update(type_, x1, y1, x2, y2, c));
      } else {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        frle(j, y1, y2) {
          flre(i, x1, x2) {
            bool printed = false;
            frle(k, 0, ups.size() - 1) {
              if(ups[k].type == 0) {
                if(check(i, j, ups[k].x1, ups[k].y1, ups[k].x2)) {
                  cout << ups[k].col;
                  printed = true;
                  break;
                }
              } else if(ups[k].type == 1) {
                if(check(i, j, ups[k].x1, ups[k].y1, ups[k].x2, ups[k].y2)) {
                  cout << ups[k].col;
                  printed = true;
                  break;
                }
              }
            }
            if(!printed) cout << ".";
          }
          cout << "\n";
        }
      }
    }
  }
  return 0;
}
