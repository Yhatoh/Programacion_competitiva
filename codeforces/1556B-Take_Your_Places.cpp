/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define sortv(vec) sort(vec.begin(), vec.end())

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

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vi nums(n);
    vi parity1(n);
    vi parity2(n);
    int ones = 0;
    int zero = 0;

    int o, z;
    o = z = -1;
    fn(i, n) {
      cin >> nums[i];
      parity1[i] = nums[i] % 2;
      parity2[i] = nums[i] % 2;
      if(o == -1 && parity1[i]) o = i;
      else if(z == -1 && !parity1[i]) z = i;

      if(nums[i] % 2) ones += 1;
      else zero++;
    }
    
    if(abs(ones - zero) > 1) {
      cout << -1 << "\n";
      continue;
    }
    if(n == 1) {
      cout << 0 << "\n";
      continue;
    }


    ll ans_1 = 0;
    int back_o = o;
    int back_z = z;
    {
      int curr_pos = 0;
      int curr = 0;
      while(o < n && z < n) {
        if(curr == 0 && z == curr_pos) {
          for(z = z + 1; z < n; z++) {
            if(parity1[z] == 0) {
              break;
            }
          }
          curr = 1;
        } else if(curr == 1 && o == curr_pos) {
          for(o = o + 1; o < n; o++) {
            if(parity1[o] == 1) {
              break;
            }
          }
          curr = 0;
        } else if(curr == 0 && z != curr_pos) {
          swap(parity1[o], parity1[z]);
          ans_1 += z - o;
          for(o = o + 1; o < n; o++) {
            if(parity1[o] == 1) break;
          }
          for(z = z + 1; z < n; z++) {
            if(parity1[z] == 0) break;
          }
          curr = 1;
        } else if(curr == 1 && o != curr_pos) {
          swap(parity1[o], parity1[z]);
          ans_1 += o - z;
          for(o = o + 1; o < n; o++) {
            if(parity1[o] == 1) break;
          }
          for(z = z + 1; z < n; z++) {
            if(parity1[z] == 0) break;
          }
          curr = 0;
        }
        curr_pos++;
      }
      fn(i, n - 1) {
        if(parity1[i] == parity1[i + 1]) ans_1 = 1000000000000000;
      }
    }
    ll ans_0 = 0;
    {
      o = back_o;
      z = back_z;
      int curr_pos = 0;
      int curr = 1;
      while(o < n && z < n) {
        if(curr == 0 && z == curr_pos) {
          for(z = z + 1; z < n; z++) {
            if(parity2[z] == 0) {
              break;
            }
          }
          curr = 1;
        } else if(curr == 1 && o == curr_pos) {
          for(o = o + 1; o < n; o++) {
            if(parity2[o] == 1) {
              break;
            }
          }
          curr = 0;
        } else if(curr == 0 && z != curr_pos) {
          swap(parity2[o], parity2[z]);
          ans_0 += z - o;
          for(o = o + 1; o < n; o++) {
            if(parity2[o] == 1) break;
          }
          for(z = z + 1; z < n; z++) {
            if(parity2[z] == 0) break;
          }
          curr = 1;
        } else if(curr == 1 && o != curr_pos) {
          swap(parity2[o], parity2[z]);
          ans_0 += o - z;
          for(o = o + 1; o < n; o++) {
            if(parity2[o] == 1) break;
          }
          for(z = z + 1; z < n; z++) {
            if(parity2[z] == 0) break;
          }
          curr = 0;
        }
        curr_pos++;
      }
      fn(i, n - 1) {
        if(parity2[i] == parity2[i + 1]) ans_0 = 1000000000000000;
      }
    }
    cout << min(ans_0, ans_1) << "\n";
  }
  return 0;
}
