#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string res;
    cin >> res;

    for (int i = 0; i < n - 3; ++i){
      string next;
      cin >> next;
      if(res[res.length() - 1] == next[0]){
        res.append(1, next[1]);
      } else {
        res.append(1, next[0]);
        res.append(1, next[1]);
      }
    }

    if(res.length() != n){
      res.append(1, 'b');
    }
    cout << res << "\n";
  }
  return 0;
}