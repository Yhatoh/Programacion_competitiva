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
    int n, m;
    cin >> n >> m;
    vector< string > grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char left = 'E';
        if(j > 0) left = grid[i][j - 1];

        char up = 'E';
        if(i > 0) up = grid[i - 1][j];

        vector< int > used = {0, 0, 0, 0, 0};
        used[up - 'A'] = 1;
        used[left - 'A'] = 1;
        used[grid[i][j] - 'A'] = 1;

        if(!used[0]) grid[i][j] = 'A';
        else if(!used[1]) grid[i][j] = 'B';
        else if(!used[2]) grid[i][j] = 'C';
        else if(!used[3]) grid[i][j] = 'D';
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
        cout << grid[i][j] << "";
      cout << "\n";
    }
  }
  return 0;
}
