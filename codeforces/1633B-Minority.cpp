#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(2);
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    vector< int > vec(2, 0);
    for (int i = 0; i < s.length(); ++i){
      if(s[i] == '0') vec[0]++;
      else vec[1]++;
    }
    
    cout << min(vec[0], vec[1]) - (vec[0] == vec[1] ? 1 : 0) << "\n";
  }
  //5
  //
  return 0;
}