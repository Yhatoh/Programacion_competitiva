#include <bits/stdc++.h>
using namespace std;

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
    vector< long long > nums(n);  
    if(n == 2) cout << "1 3\n";
    else if(n % 2 == 1) {
      nums[n / 2] = n;
      for(int i = n / 2 - 1; i >= 0; i--)
        nums[i] = nums[i + 1] - 1;
      for(int i = n / 2 + 1; i < n; i++)
        nums[i] = nums[i - 1] + 1;

      for(int i = 0; i < n; i++)
        nums[i] += 2;
      nums[n - 1]++;
      nums[0]--;
      nums[n - 2]++;
      for(auto i : nums)
        cout << i << " ";
    } else { 
      int val = n / 2;
      for(int i = 0; i < n; i++) {
        if(val == n) val++;
        nums[i] = val++;
      }
      for(auto i : nums) 
        cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
