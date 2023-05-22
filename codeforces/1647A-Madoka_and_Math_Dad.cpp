#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int howManyTwo = n / 2;
    int howManyOne = n % 2;
    while(howManyTwo > howManyOne + 1){
      howManyTwo -= 1;
      howManyOne += 2;
    }
    bool altern = howManyTwo >= howManyOne;
    while(howManyOne > 0 && howManyTwo > 0){
      if(altern){
        cout << 2;
        altern = !altern;
        howManyTwo--;
      } else {
        cout << 1;
        altern = !altern;
        howManyOne--;
      }
    }

    if(howManyOne){
      cout << 1;
    }
    if(howManyTwo){
      cout << 2;
    }
    cout << "\n";
  }
  return 0;
}