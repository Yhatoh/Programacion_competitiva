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
bool cycle(map< char, char > &mp, vector< bool > &vis, char c) {
  if(mp.find(c) == mp.end()) return false;

  vis[c - 'a'] = 1;
  if(vis[mp[c] - 'a']) return true;
  return cycle(mp, vis, mp[c]);
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
    string s, t;
    cin >> s >> t;
    map< char, char > mp;
    bool possible = true;
    fn(i, n) {
      auto itr = mp.find(s[i]);
      if(itr == mp.end()) {
        mp[s[i]] = t[i];
      } else if(itr->second != t[i]) {
        possible = false;
        break;
      }
    }
    if(possible) {
      int count = 0;
      vector< bool > vis('z' - 'a' + 1, 0);
      feach(p, mp) {
        if(vis[p.first - 'a'] == 0 && p.first != p.second) {
          count += cycle(mp, vis, p.first);
          fill(vis.begin(), vis.end(), 0);
        }
      }

      feach(p, mp) {
        count += p.first != p.second;
      }
      cout << count << "\n";
    } else {
      cout << "-1" << "\n";
    }
  }
  return 0;
}
