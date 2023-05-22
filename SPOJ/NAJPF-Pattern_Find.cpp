#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t;
  cin >> t;

  ll m = 1e9 + 7;
  ll p = 31; 
  
  vector< ll > pow_s(1000001);

  pow_s[0] = 1;
  for(int i = 1; i < 1000001; i++){
    pow_s[i] = (pow_s[i - 1] * p) % m; 
  }

  int t_i = 0;
  while(t > t_i){
    string word;
    string pattern;
    cin >> word >> pattern;

    ll n = word.length();
    ll n_pat = pattern.length();

    vector< ll > hash_word(n + 1, 0);
    // first letter
    hash_word[0] = 0;
    for(int i = 1; i <= n; i++){
      ll char_to_num = (word[i - 1] - 'a' + 1);
      ll prev_hash = hash_word[i - 1]; 
      hash_word[i] = ((char_to_num * pow_s[i - 1]) % m + prev_hash) % m;   
    }
    
    vector< ll > hash_pattern(n_pat + 1, 0);
    // first letter
    hash_pattern[0] = 0;
    for(int i = 1; i <= n_pat; i++){
      ll char_to_num = (pattern[i - 1] - 'a' + 1);
      ll prev_hash = hash_pattern[i - 1]; 
      hash_pattern[i] = ((char_to_num * pow_s[i - 1]) % m + prev_hash) % m;   
    }
    vector< ll > occurences;
    for(int i = 1; i <= n - n_pat + 1; i++){
      ll hash_sub_word = (hash_word[i + n_pat - 1] - hash_word[i - 1] + m) % m;
      if(hash_sub_word == (hash_pattern[n_pat] * pow_s[i - 1]) % m){
        occurences.push_back(i);
      }
    }

    if(occurences.size() > 0){
      cout << occurences.size() << "\n";
      for(int i = 0; i < occurences.size() - 1; i++){
        cout << occurences[i] << " "; 
      }
      cout << occurences[occurences.size() - 1] << "\n";
    } else {
      cout << "Not Found\n";
    }
    t_i++;
    if(t_i != t){
      cout << "\n";
    }
  }
  return 0;
}
