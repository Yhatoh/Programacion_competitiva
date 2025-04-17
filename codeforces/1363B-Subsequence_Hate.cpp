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
    string s;
    cin >> s;
    int n = s.length();
    vector< int > p_1(n, 0);
    vector< int > p_0(n, 0);
    vector< int > s_1(n, 0);
    vector< int > s_0(n, 0);

    p_1[0] = s[0] == '0';
    p_0[0] = s[0] == '1';

    s_1[n - 1] = s[n - 1] == '0';
    s_0[n - 1] = s[n - 1] == '1';

    for(int i = 1; i < n; i++) {
      p_1[i] = p_1[i - 1] + (s[i] == '0');
      p_0[i] = p_0[i - 1] + (s[i] == '1');
    }
    for(int i = n - 2; i >= 0; i--) {
      s_1[i] = s_1[i + 1] + (s[i] == '0');
      s_0[i] = s_0[i + 1] + (s[i] == '1');
    }

    int ans = n;
    for(int i = 0; i < n - 1; i++) {
      ans = min(ans, min(p_1[i] + s_0[i + 1], p_0[i] + s_1[i + 1]));
    }
    vector< int > fans = {ans, p_1[n - 1], p_0[n - 1], s_1[0], s_0[0]};
    cout
      << *min_element(fans.begin(), fans.end())
      << "\n";
  }
  return 0;
}
