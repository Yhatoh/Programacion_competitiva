#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector< vector< int >> mapita(12, vector< int >(12, 0));
    long long ans = 0;
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      for(int j = 0; j < 2; j++){
        for(char c = 'a'; c <= 'k'; c++){
          if(c != s[j]){
            string aux = s;
            aux[j] = c;
            ans += mapita[aux[0] - 'a'][aux[1] - 'a'];
          }
        }
      }
      mapita[s[0] - 'a'][s[1] - 'a']++;
    }
    cout << ans << "\n";
  }
  return 0;
}
