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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector< int > sheeps;

    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '*') sheeps.push_back(i);
    }

    if(sheeps.size() == s.length() || sheeps.size() <= 1) {
      cout << 0 << "\n";
      continue;
    }
    auto moves_lr = [&] (int point) {
      long long local_ans = 0;
      long long moved = 0;
      for(int i = point; i >= 0; i--) {
        if(s[i] == '*') {
          local_ans += point - i - moved;
          moved++;
        }
      }
      moved = (moved > 0 ? 1 : 0);
      for(int i = point + moved; i < s.length(); i++) {
        if(s[i] == '*') {
          local_ans += i - point - moved;
          moved++;
        }
      }
      return local_ans;
    };

    auto moves_rl = [&] (int point) {
      long long local_ans = 0;
      long long moved = 0;
      for(int i = point; i < s.length(); i++) {
        if(s[i] == '*') {
          local_ans += i - point - moved;
          moved++;
        }
      }
      moved = (moved > 0 ? 1 : 0);
      for(int i = point - moved; i >= 0; i--) {
        if(s[i] == '*') {
          local_ans += point - i - moved;
          moved++;
        }
      }
      return local_ans;
    };
    long long ans = 1000000000000000;
    if(sheeps.size() % 2 == 1) {
      ans = min(moves_rl(sheeps[sheeps.size() / 2]), ans);
      if(sheeps.size() / 2 + 1 < n)
        ans = min(moves_rl(sheeps[sheeps.size() / 2] + 1), ans);
      if(sheeps.size() / 2 - 1 >= 0)
        ans = min(moves_rl(sheeps[sheeps.size() / 2] - 1), ans);
    } else {
      ans = min(moves_rl(sheeps[sheeps.size() / 2]), ans);
      if(sheeps.size() / 2 + 1 < n)
        ans = min(moves_rl(sheeps[sheeps.size() / 2] + 1), ans);
      if(sheeps.size() / 2 - 1 >= 0)
        ans = min(moves_rl(sheeps[sheeps.size() / 2] - 1), ans);

      if(sheeps.size() / 2 + 2 < n)
        ans = min(moves_rl(sheeps[sheeps.size() / 2] + 2), ans);
    }
    cout << ans << "\n";
  }
  return 0;
}
