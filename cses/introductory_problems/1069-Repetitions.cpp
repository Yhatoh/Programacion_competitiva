#include<bits/stdc++.h>
using namespace std;

int main(){
  string dna;

  cin >> dna;

  char prev = ' ';
  int longest = 0;
  int actual = 0;
  for(int i = 0; i < dna.length(); i++){
    //cout << "-" << prev << "-" << dna[i] << "-\n";
    if(prev == dna[i]){
      actual++;
    } else {
      if(actual > longest) longest = actual;
      actual = 1;
    }
    prev = dna[i];
  }

  if(actual > longest) longest = actual;
  cout << longest << "\n";
  return 0;
}