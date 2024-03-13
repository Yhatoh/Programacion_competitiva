/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define feach(x, ds) for(auto &x : ds)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;
typedef long double ld; typedef vector< ld > vld;
typedef vector< vld > vvld; typedef pair< ld, ld > pldld;
typedef vector< pldld > vpldld; typedef vector< vpldld >  vvpldld;

struct bit_vector {
  uint64_t size;
  vector< uint64_t > bv;
  bit_vector() : size(0) {}
  uint64_t get(uint64_t i) const {
    uint64_t b = i / 64;
    uint64_t ib = i % 64;
    return (bv[b] & (1ULL << ib)) >> ib;
  }
  void set(uint64_t i) {
    uint64_t b = i / 64;
    uint64_t ib = i % 64;
    bv[b] |= (1ULL << ib);
  }
  void push_back(uint64_t bit) {
    if(size % 64 == 0) bv.push_back(0);
    uint64_t b = size / 64;
    uint64_t ib = size++ % 64;
    bv[b] |= (bit << ib);
  }
  bit_vector operator~() {
    bit_vector bv = *this;
    for(uint64_t i = 0; i < bv.bv.size(); i++)
      bv.bv[i] = ~bv.bv[i];
    if(size % 64)
      for(uint64_t i = size % 64; i < 64; i++)
        bv.bv[bv.bv.size() - 1] &= (~(1ULL << i));
    return bv;
  }
  friend std::ostream& operator<<(std::ostream& os, const bit_vector& bv) {
    for(uint64_t i = 0; i < bv.size; i++) {
      if(bv.bv[i / 64] < (1ULL << 32) && (i % 64) >= 32) cout << 0;
      else cout << ((bv.bv[i / 64] & (1ULL << (i % 64))) ? 1 : 0);
    } 
    return os;
  }
  bit_vector& operator=(const bit_vector& o) {
    if (this != &o)
      size = o.size, bv = o.bv;
    return *this;
  }
  bool operator==(const bit_vector& o) const {
    if(size != o.size) return false;
    for(uint64_t i = 0; i < size; i++)
      if(get(i) != o.get(i)) return false;
    return true;
  }
  bool operator<(const bit_vector& o) const {
    for(uint64_t i = 0; i < size && i < o.size; i++)
      if(get(i) != o.get(i)) return get(i) < o.get(i);
    return size < o.size;
  }
  bool operator>(const bit_vector& o) const {
    for(uint64_t i = 0; i < size && i < o.size; i++)
      if(get(i) != o.get(i)) return get(i) > o.get(i);
    return size > o.size;
  }
  bool operator<=(const bit_vector& o) const {
    for(uint64_t i = 0; i < size && i < o.size; i++)
      if(get(i) != o.get(i)) return get(i) <= o.get(i);
    return size <= o.size;
  }
  bool operator>=(const bit_vector& o) const {
    for(uint64_t i = 0; i < size && i < o.size; i++)
      if(get(i) != o.get(i)) return get(i) >= o.get(i);
    return size >= o.size;
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
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector< bit_vector > bvs(n);
    fn(i, n) {
      int x;
      cin >> x;
      fn(j, 31)
        bvs[i].push_back((((x & (1 << j)) == 0) ? 0 : 1));
    }

    int groups = n;
    map< bit_vector, int > mp;
    fn(i, n) {
      bit_vector flipped = ~bvs[i];
      if(mp.find(flipped) != mp.end()) {
        groups--;
        mp[flipped]--;
        if(mp[flipped] == 0) mp.erase(flipped);
      } else {
        mp[bvs[i]]++;
      }
    }
    cout << groups << "\n";
  }
  return 0;
}
