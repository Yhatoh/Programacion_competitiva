//1 2
//diff -> 1

//3 5
//0 0->-1 1->3 5

//5 3
//

//6 6
//0 0->6 6

//8 0
//0 0->4 -4->8 0

//0 0
//0 0

//7 10
//0 0->-2 2->
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int c, d;
    cin >> c >> d;
    if(abs(c - d) % 2){
      cout << "-1\n";
    } else if(c == 0 && c == d){
      cout << "0\n";
    } else if(c == d){
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
  return 0;
}