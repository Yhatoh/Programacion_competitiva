#include <bits/stdc++.h>
using namespace std;

void print(vector< long long > &nums){
  for(long long i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }cout << "\n";
}

long long changePos(vector< long long > &nums){
  long long swaps = 0;
  long long n = nums.size();
  for(long long i = 1; i < n; i++){
    //print(nums);
    if(nums[i - 1] % 2 == nums[i] % 2){
      long long j;
      for(j = i + 1; j < n; j += 1){
        if(nums[i] % 2 != nums[j] % 2){
          break;
        }
      }
      if(j == n) break;
      for(long long k = j; k > i; k--){
        swaps++;
        long long aux = nums[k];
        nums[k] = nums[k - 1];
        nums[k - 1] = aux;
      } 
    }
  }
  return swaps;
}

long long changePosRev(vector< long long > &nums){
  long long swaps = 0;
  long long n = nums.size();
  for(long long i = n - 2; i > 0; i--){
    //print(nums);
    if(nums[i + 1] % 2 == nums[i] % 2){
      long long j;
      for(j = i - 1; j >= 0; j -= 1){
        if(nums[i] % 2 != nums[j] % 2){
          break;
        }
      }
      if(j == -1) break;
      for(long long k = j; k < i; k++){
        swaps++;
        long long aux = nums[k];
        nums[k] = nums[k + 1];
        nums[k + 1] = aux;
      } 
    }
  }
  return swaps;
}

int main(){
  //ios_base::sync_with_stdio(false); 
  //cin.tie(NULL);
  //cout.setf(ios::fixed);
  //cout.precision(4);
	long long t;
  cin >> t;
  while(t--){
    long long n;
    cin >> n;
    vector< long long > nums(n);
    vector< long long > nums2(n);
    
    long long i;
    for(i = 0; i < n; i++){
      cin >> nums[i];
      nums2[i] = nums[i];
    }

    long long swaps1 = changePos(nums);
    long long swaps2 = changePosRev(nums2);

    for(i = 0; i < n - 1; i++){
      if(nums[i] % 2 == nums[i + 1] % 2) break;
    }

    long long j;
    for(j = 0; j < n - 1; j++){
      if(nums2[i] % 2 == nums2[i + 1] % 2) break;
    }

    if(i == n - 1){
      cout << swaps1 << "\n";
    } else if(j == n - 1){
      cout << swaps2 << "\n";
    } else {
      cout << "-1\n";
    }
  }
}