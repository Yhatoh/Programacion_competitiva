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

template <typename T>
struct min_stack {
  stack<pair<T, T>> S;
  void push(T x) {
    T new_min = S.empty() ? x : min(x, S.top().second);
    S.push({x, new_min});
  }
  bool empty() { return S.empty(); }
  int size() { return S.size(); }
  void pop() { S.pop(); }
  T top() { return S.top().first; }
  T getMin() { return S.top().second; }
};

template <typename T>
struct min_queue {
  min_stack<T> in, out;
  void push(T x) { in.push(x); }
  bool empty() { return in.empty() and out.empty(); }
  int size() { return in.size() + out.size(); }
  void pop() {
    if (out.empty())
      for (;in.size(); in.pop()) out.push(in.top());
    out.pop();
  }
  T front() {
    if (!out.empty()) return out.top();
    for (;in.size(); in.pop()) out.push(in.top());
    return out.top();
  }
  T getMin() {
    if (in.empty()) return out.getMin();
    if (out.empty()) return in.getMin();
    return min(in.getMin(), out.getMin());
  }
};

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

    min_queue< long long > q;
    q.push(x);
    long long value = x;
    long long ans = 0;

    for(int i = 1; i < k; i++) {
      value = ((value * a) % c + b) % c;
      q.push(value);
    }

    ans ^= q.getMin();

    for(int i = 0; i < n - k; i++) {
      q.pop();
      value = (value * a % c + b) % c;
      q.push(value);

      ans ^= q.getMin();
    }
    cout << ans << "\n";
  }
  return 0;
}
