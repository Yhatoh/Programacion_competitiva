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


template< typename T >
ostream& operator<<(ostream& os, const set< T > &m) {
  os << "{";
  for(auto p : m) {
    os << p << " ";
  }
  os << "}";
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
    int n;
    cin >> n;
    vi cards(n);
    fn(i, n) cin >> cards[i];

    if(n == 1) {
      cout << -1 << "\n";
    } else {
      bool flag1 = true;
      set< int > nums;
      fn(i, n) nums.insert(cards[i]);
      if(nums.size() > 1) flag1 = false;

      if(flag1) {
        cout << 1 << "\n";
        cout << cards[0] << "\n";
      } else {
        bool flag2 = true;
        vi diff(n - 1) ;
        fn(i, n - 1) diff[i] = cards[i + 1] - cards[i];
        fn(i, diff.size() - 1) if(diff[i] != diff[i + 1]) flag2 = false;

        sortv(cards);
        set< int > ans;
        if(flag2 && n > 2) {
          ans.insert(cards[0] - diff[0]);
          ans.insert(cards[n - 1] + diff[0]);
          if(n == 2) {
            int middle = cards[0] + cards[1];
            if(middle % 2 == 0) ans.insert(middle / 2);
          }
        } else {
          vi sorted_diff(n - 1);
          fn(i, n - 1) sorted_diff[i] = cards[i + 1] - cards[i];

          bool flag3 = true;
          fn(i, sorted_diff.size() - 1) if(sorted_diff[i] != sorted_diff[i + 1]) flag3 = false;
          
          if(flag3) {
            ans.insert(cards[0] - sorted_diff[0]);
            ans.insert(cards[n - 1] + sorted_diff[0]);
            if(n == 2) {
              int middle = cards[0] + cards[1];
              if(middle % 2 == 0) ans.insert(middle / 2);
            }
          } else {
            map< int, int > mapita;
            fn(i, n - 1) mapita[sorted_diff[i]]++;

            if(mapita.size() <= 2) {
              int index = -1;
              fn(i, n - 1) if(mapita[sorted_diff[i]] == 1) index = i;

              map< int, int > backup = mapita;
              if(index != -1 && (cards[index] + cards[index + 1]) % 2 == 0) {
                int new_elem = (cards[index] + cards[index + 1]) / 2;
                mapita.erase(sorted_diff[index]);
                mapita[new_elem - cards[index]]++;
                mapita[cards[index + 1] - new_elem]++;
                if(mapita.size() == 1) ans.insert(new_elem);
                else {
                  mapita = backup;
                  int index2 = -1;
                  fn(i, n - 1) if(i != index && mapita[sorted_diff[i]] == 1) index2 = i;
                  index = index2;
                  if((cards[index] + cards[index + 1]) % 2 == 0) {
                    int new_elem = (cards[index] + cards[index + 1]) / 2;
                    mapita.erase(sorted_diff[index]);
                    mapita[new_elem - cards[index]]++;
                    mapita[cards[index + 1] - new_elem]++;
                    if(mapita.size() == 1) ans.insert(new_elem);
                  }
                }
              } else {
                mapita = backup;
                int index2 = -1;
                fn(i, n - 1) if(i != index && mapita[sorted_diff[i]] == 1) index2 = i;
                index = index2;
                if((cards[index] + cards[index + 1]) % 2 == 0) {
                  int new_elem = (cards[index] + cards[index + 1]) / 2;
                  mapita.erase(sorted_diff[index]);
                  mapita[new_elem - cards[index]]++;
                  mapita[cards[index + 1] - new_elem]++;
                  if(mapita.size() == 1) ans.insert(new_elem);
                }
              }
            }
          }
        }
        cout << ans.size() << "\n";
        for(auto itr = ans.begin(); itr != ans.end(); itr++) cout << *itr << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
