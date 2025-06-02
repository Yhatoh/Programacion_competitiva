/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

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
    
    std::bitset<5> x(vec[i]);
    os << x;
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
    int n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector< long long > nums;
    nums.push_back(x);
    for(int i = 1; i < n; i++) {
      nums.push_back(((nums.back() * a) % c + b) % c);
    }

    vector< long long > prefix_or;
    long long prefix_aux = 0;
    for(int i = 0; i < n; i++) {
      if(i % k == 0) {
        prefix_aux = 0;
      }
      prefix_aux |= nums[i];
      prefix_or.push_back(prefix_aux);
    }
 
    vector< long long > suffix_or;
    long long suffix_aux = 0;
    for(int i = n - 1; i >= 0; i--) {
      if(i % k == k - 1) {
        suffix_aux = 0;
      }
      suffix_aux |= nums[i];
      suffix_or.push_back(suffix_aux);
    }
    
    reverse(suffix_or.begin(), suffix_or.end());

    long long ans = 0;
    for(int i = k - 1; i < n; i++) {
      if(i % k == k - 1) {
        ans ^= prefix_or[i];
      } else {
        ans ^= prefix_or[i] | suffix_or[i - k + 1];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
