/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

template< typename T >
ostream& operator<<(ostream& os, const set< T > &s);
template< typename T, typename T2 >
ostream& operator<<(ostream& os, const pair< T, T2 > &p);
template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec);
template< typename T, typename T2 >
ostream& operator<<(ostream& os, const map< T, T2 > &m);

template< typename T >
ostream& operator<<(ostream& os, const set< T > &s) {
  os << "{";
  for(uint64_t i = 0; i < s.size(); i++) {
    os << s[i];
    if(i != s.size() - 1)
      os << ", ";
  }
  os << "}";
  return os;
}

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

#define dbg(var) cout << #var << " = " << var << "\n";

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
    int n, a, b;
    cin >> n >> a >> b;

    if(a == 0 && b > 0) cout << "NO\n";
    else if(b == 0 && a > 0) cout << "NO\n";
    else if(a + b > n) cout << "NO\n";
    else {
      vector< int > p_a, p_b;

      int tie = n - (a + b);

      int mina = 1;
      int minb = 1;
      while(tie--) {
        p_a.push_back(mina++);
        p_b.push_back(minb++);
      }

      int maxa = n;
      int maxb = n;
      if(mina == maxa) {
        cout << "NO\n";
      } else {
        int newmina = mina + b;

        for(int i = 0; i < a + b; i++) {
          p_a.push_back(newmina++);
          if(newmina == n + 1) newmina = mina;
          p_b.push_back(minb++);
        }
        cout << "YES\n";
        for(auto p : p_a) cout << p << " ";
        cout << "\n";
        for(auto p : p_b) cout << p << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
