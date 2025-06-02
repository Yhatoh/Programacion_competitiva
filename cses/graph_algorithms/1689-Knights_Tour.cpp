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

template< typename T, typename T2 >
ostream& operator<<(ostream& os, const pair< T, T2 > &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
  os << "[";
  for(uint64_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if(i != vec.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}

void gen_opt(vpii &opts, int x, int y) {
  opts[1].first = x - 2;
  opts[1].second = y - 1;

  opts[3].first = x - 2;
  opts[3].second = y + 1;

  opts[0].first = x - 1;
  opts[0].second = y - 2;

  opts[2].first = x - 1;
  opts[2].second = y + 2;
 
  opts[7].first = x + 1;
  opts[7].second = y - 2;

  opts[4].first = x + 1;
  opts[4].second = y + 2;

  opts[5].first = x + 2;
  opts[5].second = y + 1;

  opts[6].first = x + 2;
  opts[6].second = y - 1;
}

bool valid(int x, int y) {
  if(x >= 0 && x < 8 && y >= 0 && y < 8) return true;
  return false;
}

int count(vpii &opts) {
  int sum = 0;
  fn(i, opts.size()) {
    if(valid(opts[i].first, opts[i].second)) sum++;
  }
  return sum;
}

int gen_path(vvi &square, int c, int x, int y) {
  vpii opts(8);
  square[x][y] = c;
  if(c == 64) return 1;

  gen_opt(opts, x, y);

  vpii opts2(8);
  vector< pair< int, pair< int, int > > > sorted;
  fn(i, 8) {
    int _x = opts[i].first;
    int _y = opts[i].second;
    if(valid(_x, _y) && !square[_x][_y]) {
      gen_opt(opts2, _x, _y);
      int res = count(opts2);
      sorted.push_back({res, {_x, _y}});
    }
  } 
  sortv(sorted);
  fn(i, sorted.size())
    if(gen_path(square, c + 1, sorted[i].second.first, sorted[i].second.second)) return 1;
  
  square[x][y] = 0;
  return 0;
}

#define debug 1

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    vvi square(8, vi(8, 0));
    int x, y;
    cin >> x >> y;
    x--; y--;
    gen_path(square, 1, y, x);
    fn(i, 8) {
      fn(j, 8) {
        cout << square[i][j] << " ";
      }
      cout << "\n";
    }

  }
  return 0;
}
