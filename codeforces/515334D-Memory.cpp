/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;
typedef long double ld; typedef vector< ld > vld;
typedef vector< vld > vvld; typedef pair< ld, ld > pldld;
typedef vector< pldld > vpldld; typedef vector< vpldld >  vvpldld;

void sum(int &a, int &b, int &carry) {
  if(a && b) {
    a = 0;
    carry = 1;
  } else if((b || a) && carry) {
    a = 0;
    carry = 1;
  } else {
    a += b + carry;
    carry = 0;
  }
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

#define MAX_SIZE 60
#define debug 1

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
    bool sign_ = 0;
    vi number(MAX_SIZE, 0);

    int pos_int = 0;
    bool one = 0;
    bool no_zero = 0;
    for(int i = 0; i < n; i++) {

      int x;
      cin >> x;
      
      bool sign = (x < 0 ? 1 : 0);
      x = abs(x);
      int backup = x;
      vi bin_rep;
      while(x > 0) {
        if(x % 2) bin_rep.push_back(1);
        else bin_rep.push_back(0);
        x /= 2;
      }

      while(bin_rep.size() < 31) bin_rep.push_back(0);

      if(sign) {
        int carry = 1;
        for(int j = 0; j < bin_rep.size(); j++) {
          if(bin_rep[j]) {
            bin_rep[j] = 0;
            bin_rep[j] += carry;
            carry = 0;
          } else {
            bin_rep[j] = 1;
            if(carry) {
              bin_rep[j] = 0;
            }
          }
        }
      }

      int real_num = 0;
      int pow_2 = 0;
 
      if(sign_) {
        for(int j = pos_int; j < pos_int + bin_rep.size(); j++) {
          real_num |= (number[j] << pow_2);
          pow_2++;
        }
        real_num |= (1 << 31);
        real_num *= -1;
      } else {
        for(int j = pos_int; j < pos_int + bin_rep.size(); j++) {
          real_num |= (number[j] << pow_2);
          pow_2++;
        }
      }

      if(sign != sign_) {
        if(real_num < backup) sign_ = sign;
      }

      DBG(pos_int);
      DBG(sign_);
      DBG(number);
      DBG(real_num);
      DBG(sign);
      DBG(bin_rep);
      DBG(backup);

      int carry = 0;
      for(int j = pos_int; j < pos_int + bin_rep.size(); j++) {
        if(sign_ == 0) {
          if(sign == 0) {
            sum(number[j], bin_rep[j - pos_int], carry);
          } else {
            //bin_rep[j - pos_int] = (bin_rep[j - pos_int] == 0 ? 1 : 0);
            sum(number[j], bin_rep[j - pos_int], carry);
          }
        } else {
          if(sign == 0) {
            //number[j] = (number[j] == 0 ? 1 : 0);
            sum(number[j], bin_rep[j - pos_int], carry);
          } else {
            //bin_rep[j - pos_int] = (bin_rep[j - pos_int] == 0 ? 1 : 0);
            //number[j] = (number[j] == 0 ? 1 : 0);
            sum(number[j], bin_rep[j - pos_int], carry);
          }
        }
      }

      if(no_zero == 0) {
        if(sign != sign_) {
          bool check_zero = 0;
          for(int j = pos_int; j < pos_int + bin_rep.size(); j++) {
            if(number[j] == 0){
              check_zero = 1;
            }
          }
          if(!check_zero) {
            for(int j = pos_int; j < pos_int + bin_rep.size(); j++) {
              number[j] = 0;
            }
          }
          sign_ = 0;
        }
        for(int j = pos_int; j < pos_int + bin_rep.size(); j++) {
          if(number[j] == 1) {
            one = true;
            if(j == pos_int) no_zero = true;
            break;
          }
        }
      }

      if(!no_zero && !one) cout << "0";
      else if(sign_) cout << "-";
      else cout << "+";
      cout << "\n";

      DBG(number);
      if(sign_) {
        int real_num = 0;
        int pow_2 = 0;
        for(int j = pos_int; j < pos_int + bin_rep.size(); j++) {
          real_num |= (number[j] << pow_2);
          pow_2++;
        }
        real_num |= (1 << 31);
        real_num /= 2;

        vi bin_rep;
        real_num = abs(real_num);
        while(real_num > 0) {
          if(real_num % 2) bin_rep.push_back(1);
          else bin_rep.push_back(0);
          real_num /= 2;
        }

        while(bin_rep.size() < 31) bin_rep.push_back(0);

        int carry = 1;
        for(int j = 0; j < bin_rep.size(); j++) {
          if(bin_rep[j]) {
            bin_rep[j] = 0;
            bin_rep[j] += carry;
            carry = 0;
          } else {
            bin_rep[j] = 1;
            if(carry) {
              bin_rep[j] = 0;
            }
          }
        }
        for(int j = pos_int + 1; j < bin_rep.size() + pos_int + 1; j++) {
          number[j] = bin_rep[j - (pos_int + 1)];
        }
      }
      pos_int++;
      one = 0;
      if(backup % 2) no_zero = 1;
      cout << "\n";
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}
