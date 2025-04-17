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

template< typename T, typename T2 >
ostream& operator<<(ostream& os, const map< T, T2 > &m) {
  os << "{";
  for(auto p : m) {
    os << "(" << p.first << "," << p.second << ")";
    os << " ";
  }
  os << "}";
  return os;
}

char inv(char x) {
  if(x == 'N') return 'S';
  if(x == 'S') return 'N';
  if(x == 'E') return 'W';
  return 'E';
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
    if(s.length() % 2) {
      cout << "NO\n";
      continue;
    }

    map< char, vi > mp;

    bool r = false;
    bool h = false;
    fn(i, n) {
      mp[s[i]].push_back(i);
      if(mp[inv(s[i])].size() > 0) {
        r = true;
        s[mp[inv(s[i])][0]] = 'R';
        s[i] = 'R';
        break;
      } 
    }

    mp.clear();
    fn(i, n) {
      if(s[i] == 'R' || s[i] == 'H') continue;

      mp[s[i]].push_back(i);

      if(mp[inv(s[i])].size() > 0) {
        h = true;
        s[mp[inv(s[i])].back()] = 'H';
        mp[inv(s[i])].pop_back();
        mp[s[i]].pop_back();
        s[i] = 'H';
      }
    }

    mp.clear();
    fn(i, n) {
      if(s[i] != 'R' && s[i] != 'H') mp[s[i]].push_back(i);
    }

    bool flag = true;
    feach(p, mp) {
      if(p.second.size() % 2) {
        flag = false;
        break;
      }

      if(p.second.size() / 2 > 0) {
        r = true;
        h = true;
        fn(i, p.second.size() / 2) {
          s[p.second[i]] = 'R'; 
        }
        flr(i, p.second.size() / 2, p.second.size()) {
          s[p.second[i]] = 'H'; 
        }
      }
    }
    if(flag && r && h)
      cout << s << "\n";
    else
      cout << "NO\n";
  }
  return 0;
}
