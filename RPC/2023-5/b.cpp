/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/
#include <bits/stdc++.h>
using namespace std;

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

bool check(vector< int > &nums) {
  for(int i = 1; i < nums.size(); i++) {
    if(nums[i - 1] > nums[i])
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  //int t = 1;
  //cin >> t;
  //while(t--) {
  int n, k;
  cin >> n >> k;
  vector< int > nums(n);
  for(int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int ans = 0;
  while(!check(nums)) {
    for(int i = 0; i + k <= n; i++) {
      sort(nums.begin() + i, nums.begin() + i + k);
    }
    ans++;
  }
  cout << ans << "\n";
  //}
  return 0;
}
