/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define DBG(var) cout << #var << " = " << var << "\n"
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef long long ll;

// Overloading the << operator for a multiset
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& myMultiset) {
    os << myMultiset.size() << " {";
    typename std::multiset<T>::const_iterator it = myMultiset.begin();
    if (it != myMultiset.end()) {
        os << *it;
        ++it;
    }
    while (it != myMultiset.end()) {
        os << ", " << *it;
        ++it;
    }
    os << "}";
    return os;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector< int > v(n);
  fn(i, n) cin >> v[i];

  multiset< int > up;
  multiset< int > low;

  fn(i, n) {
    int x = v[i];
    //cout << "BEGIN FOR" << endl;
    //DBG(low);
    //DBG(up);
    if(up.size() + low.size() == k) {
      cout << *prev(low.end()) << " ";
      int destroy = v[i - k];
      if(destroy <= *prev(low.end())) {
        low.erase(low.find(destroy));
      } else {
        up.erase(up.find(destroy));
      }
    }

    if(low.size() > 0 && x <= *prev(low.end())) {
      low.insert(x);
    } else if(up.size() > 0 && x >= *up.begin()){
      up.insert(x);
    } else {
      low.insert(x);
    }
    //cout << "AFTER ADD" << endl;
    //DBG(low);
    //DBG(up);

    if(low.size() + up.size() > 1) {
      if(low.size() < up.size()) {
        low.insert(*up.begin());
        up.erase(up.begin());
      } else if(k % 2 && low.size() > up.size() + 1) {
        up.insert(*prev(low.end()));
        low.erase(prev(low.end()));
      } else if(k % 2 == 0 && low.size() > up.size()) {
        up.insert(*prev(low.end()));
        low.erase(prev(low.end()));
      }
    }
    //cout << "POST BALANCE" << endl;
    //DBG(low);
    //DBG(up);
  }
  if(up.size() + low.size() == k) {
    cout << *prev(low.end()) << " ";
  }

  cout << "\n";
  return 0;
}
