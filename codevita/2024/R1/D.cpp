/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define dbg(var) cout << #var << " = " << var << "\n";
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

struct lane {
  int x1, y1, x2, y2;
  bool par;
};

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
    vector< lane > coords(n);
    for(int i = 0; i < n; i++) {
      cin >> coords[i].x1 >> coords[i].y1;
      cin >> coords[i].x2 >> coords[i].y2;
      if(coords[i].x1 == coords[i].x2) coords[i].par = 1;
      else coords[i].par = 0;
    }

    vector< vector< int > > matrix(101, vector< int >(101, 0));
    //vector< vector< int > > matrix(20, vector< int >(20, 0));

    for(auto coord : coords) {
      if(coord.par) {
        if(coord.y1 > coord.y2) swap(coord.y1, coord.y2);
        for(int i = coord.y1; i < coord.y2 + 1; i++) {
          matrix[coord.x1][i] = 1;
        }
      } else {
        if(coord.x1 > coord.x2) swap(coord.x1, coord.x2);
        for(int i = coord.x1; i < coord.x2 + 1; i++) {
          matrix[i][coord.y1] = 1;
        }
      }
    }
//
//    for(int i = 0; i < 20; i++) {
//      for(int j = 0; j < 20; j++) {
//        cout << matrix[i][j];
//      }
//      cout << "\n";
//    }
    int ans = 0;
    for(int i = 1; i < 100; i++) {
      for(int j = 1; j < 100; j++) {
        if(matrix[i][j]) {
          if(matrix[i - 1][j] && matrix[i + 1][j] && matrix[i][j + 1] &&
             matrix[i][j - 1])
            ans++;
        }
      }
    }
    cout << ans;
  }
  return 0;
}
