#include<bits/stdc++.h>
using namespace std;

int main(){
  string word;
  cin >> word;
  int n = word.length();
  vector< int > freq('Z' - 'A' + 1, 0);

  for(int i = 0; i < n; i++){
    freq[word[i] - 'A']++;
  }

  string pre;
  string post;
  int howMany = 0;
  string middle = "";
  for(int i = 'A'; i <= 'Z'; i++){
    while(freq[i - 'A'] > 1){
      pre += i;
      post += i;
      freq[i - 'A'] -= 2;
    }

    if(freq[i - 'A'] == 1){
      howMany++;
      middle += i;
    }

    if(howMany > 1) break;
  }
  reverse(post.begin(), post.end());
  
  if(howMany > 1) cout << "NO SOLUTION\n";
  else cout << pre + middle + post << "\n";
  return 0;
}