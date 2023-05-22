/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/
#include <bits/stdc++.h>
using namespace std;

#define F(i,L,R) for (int i = L; i < R; i++) 
#define debug(x) cerr << #x << ": " << x << endl

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
ostream& operator<<(ostream& os, const multiset< T > &m) {
  os << "{";
  for(auto p : m) {
    os << p;
    os << " ";
  }
  os << "}";
  return os;
}
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  cin >> t;
  multiset< int > b;
  vector< int > a;
  while(t--) {
    int n, k;
    cin >> n >> k;
    a.assign(n, 0);
    F(i, 0, n) cin >> a[i];
    F(i, 0, n) {
      int x;
      cin >> x;
      b.insert(x);
    }

    F(i, 0, n) {
      auto test = b.lower_bound(a[i] - k);
      auto test2 = b.lower_bound(a[i] + k);
      if(test2 != b.begin() && test2 != b.end() && *test2 > a[i] + k) test2 = prev(test2);
      if(test == b.end()) {
        a[i] = *test2;
        b.erase(test2);
      } else if(test2 == b.end()) {
        a[i] = *test;
        b.erase(test);
      } else if(abs(a[i] - *test2) > k) {
        a[i] = *test;
        b.erase(test);
      } else if(abs(a[i] - *test) > k) {
        a[i] = *test2;
        b.erase(test2);
      } else {
        if(abs(a[i] - (*test)) < abs(a[i] - (*test2))) {
          a[i] = *test2;
          b.erase(test2);
        } else {
          a[i] = *test;
          b.erase(test);
        }
      }
    }

    F(i, 0, n) {
      cout << a[i] << " ";
    }
    cout << "\n";
    b.clear();
    a.clear();
  }
  return 0;
}
