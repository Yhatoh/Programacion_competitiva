#include<bits/stdc++.h>
using namespace std;

bool descend(int a, int b){
  return a > b;
}

void print(vector< int > &v){
  int i;
  for(i = 0; i < ((int) v.size()) - 1; i++){
    cout << v[i] << " ";
  }
  cout << v[i] << "\n";
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(2);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector< int > nums(n);
    vector< int > found(n + 1, 0);
    for (int i = 0; i < n; ++i){
      cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), descend);

    bool flag = true;

    //cout << "NUMS: ";
    //print(nums);
    for(auto x : nums){
      //cout << "X: " << x << "\n";
      //cout << "FOUND: ";
      //print(found);
      while(x > 0){
        if(x <= n && found[x] == 0){
          found[x] = 1;
          break;
        }
        x /= 2;
      }
      if(x == 0){
        flag = false;
        break;
      }
    }

    //cout << "FOUND: ";
    //print(found);

    if(flag) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}