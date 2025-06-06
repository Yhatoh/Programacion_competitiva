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
    int n, k;
    cin >> n >> k;
    map< int, int > ntof;
    map< int, set< int > > fton;

    for(int i = 0; i < 200000; i++) fton[0].insert(i);

    vector< int > nums;
    for(int i = 0; i < k; i++) {
      int a;
      cin >> a;
      nums.push_back(a);
      fton[ntof[a]].erase(a);
      if(fton[ntof[a]].size() == 0) fton.erase(ntof[a]);
      ntof[a]++;
      fton[ntof[a]].insert(a);
    }

    cout << *(prev(fton.end())->second).begin() << " ";
    for(int i = k; i < n; i++) {
      fton[ntof[nums[i - k]]].erase(nums[i - k]);
      if(fton[ntof[nums[i - k]]].size() == 0) fton.erase(ntof[nums[i - k]]);
      ntof[nums[i - k]]--;
      fton[ntof[nums[i - k]]].insert(nums[i - k]);
      int a;
      cin >> a;
      fton[ntof[a]].erase(a);
      if(fton[ntof[a]].size() == 0) fton.erase(ntof[a]);
      ntof[a]++;
      fton[ntof[a]].insert(a);
      cout << *(prev(fton.end())->second).begin() << " ";
      nums.push_back(a);
    }
    cout << "\n";
  }
  return 0;
}
