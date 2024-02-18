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

bool cmp(string a, string b) {
    return a[0] < b[0];
}

bool cmp2(string a, string b) {
    return a[0] > b[0];
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
    string trump;
    cin >> trump;
    vector< string > cards(2 * n);
    fn(i, 2 * n) cin >> cards[i];

    vector< string > trumps;
    vector< string > no_trumps;
    fn(i, 2 * n) {
      if(cards[i][1] == trump[0]) trumps.push_back(cards[i]);
      else no_trumps.push_back(cards[i]);
    }

    vector< vector< string > > sep(4);
    fn(i, no_trumps.size()) {
      if(no_trumps[i][1] == 'C') sep[0].push_back(no_trumps[i]);
      if(no_trumps[i][1] == 'D') sep[1].push_back(no_trumps[i]);
      if(no_trumps[i][1] == 'H') sep[2].push_back(no_trumps[i]);
      if(no_trumps[i][1] == 'S') sep[3].push_back(no_trumps[i]);
    }

    sort(trumps.begin(), trumps.end(), cmp2);
    sort(sep[0].begin(), sep[0].end(), cmp);
    sort(sep[1].begin(), sep[1].end(), cmp);
    sort(sep[2].begin(), sep[2].end(), cmp);
    sort(sep[3].begin(), sep[3].end(), cmp);

    fn(i, 4) {
      if(sep[i].size() % 2 && trumps.size() > 0) sep[i].push_back(trumps[trumps.size() - 1]), trumps.pop_back();
    }

    int flag = true;
    fn(i, 4) {
      if(sep[i].size() % 2) flag = false;
    }
    if(trumps.size() % 2) flag = false;

    if(flag){
      fn(i, 4) {
        int l = 0;
        int r = sep[i].size() - 1;
        while(l < r) {
          cout << sep[i][l] << " " << sep[i][r] << "\n";
          l++; r--;
        }
      }

      reverse(trumps.begin(), trumps.end());
      int l = 0;
      int r = trumps.size() - 1;
      while(l < r) {
        cout << trumps[l] << " " << trumps[r] << "\n";
        l++; r--;
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
  return 0;
}
