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
    vector< long long > nums(n);
    for (int i = 0; i < n; ++i){
      cin >> nums[i];
    }

    if(n > 3){
      set< long long > primes1;
      while (nums[0] % 2 == 0){
        primes1.insert(2);
        nums[0] = nums[0]/2;
      }

      // n must be odd at this point. So we can skip
      // one element (Note i = i +2)
      for (int i = 3; i <= sqrt(nums[0]); i = i + 2){
        // While i divides n, print i and divide n
        while (nums[0] % i == 0){
          primes1.insert(i);
          nums[0] = nums[0]/i;
        }
      }
   
      // This condition is to handle the case when n
      // is a prime number greater than 2
      if (nums[0] > 2)
        primes1.insert(nums[0]);
      for (int i = 2; i < n; i += 2){
        for(auto itr = primes1.begin(); itr != primes1.end()){
          auto aux = *itr;
          itr++;
          if(nums[i] % aux != 0){
            primes1.erase(aux);
          }
        }
        if(primes1.size() == 0){
          break;
        }
      }

      if(primes1.size() == 0){
        cout << 0 << "\n";
        return 0;
      }

      for(int i = 1; i < n; i += 3){
        for(auto itr = primes1.begin(); itr != primes1.end()){
          auto aux = *itr;
          itr++;
          if(nums[i] % aux == 0){
            primes1.erase(aux);
          }
        }
      }

      if(primes1.size() == 0){
        
      }
      
    }
  }
  return 0;
}