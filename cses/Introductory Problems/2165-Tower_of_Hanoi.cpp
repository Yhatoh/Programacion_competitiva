#include<bits/stdc++.h>
using namespace std;

void Tower_of_Hanoi(int f, int s, int t, int n){
  if(n == 0) return;

  Tower_of_Hanoi(f, t, s, n - 1);
  cout << f << " " << t << "\n";
  Tower_of_Hanoi(s, f, t, n - 1);
}

int main(){
  int n;
  cin >> n;
  cout << (1 << n) - 1 << "\n";
  Tower_of_Hanoi(1, 2, 3, n);
  return 0;
}