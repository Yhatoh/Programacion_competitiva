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
  while(t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector< char > v(s.length());
    for(int i = 0; i < s.length(); i++) {
      v[i] = s[i];
    }
    vector< char > ans;
    for(int i = 0; i < v.size(); i++) {
      if(v[i] == '1' || v[i] == '0') continue;
      if(v[i] == '2' || v[i] == '3' || v[i] == '5' || v[i] == '7') ans.push_back(v[i]);
      if(v[i] == '4') {
        ans.push_back('3');
        ans.push_back('2');
        ans.push_back('2');
      }
      if(v[i] == '6') {
        ans.push_back('3');
        ans.push_back('5');
      }
      if(v[i] == '8') {
        ans.push_back('7');
        ans.push_back('2');
        ans.push_back('2');
        ans.push_back('2');
      }
      if(v[i] == '9') {
        ans.push_back('7');
        ans.push_back('3');
        ans.push_back('3');
        ans.push_back('2');
      }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(auto &s : ans) cout << s;
    cout << "\n";
  }
  return 0;
}
