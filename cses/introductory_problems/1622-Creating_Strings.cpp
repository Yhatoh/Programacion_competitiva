#include<bits/stdc++.h>
using namespace std;

set< string > ans;
string realWord;

void create(string word, int n, int actual, set< int > &inuse){
  if(n == actual){
    ans.insert(word);
    return;
  }

  for(int i = 0; i < n; i++){
    if(inuse.find(i) == inuse.end()){
      inuse.insert(i);
      create(word + realWord[i], n , actual + 1, inuse);
      inuse.erase(i);
    }
  }
}

int main(){
  cin >> realWord;
  set< int > inuse;
  create("", realWord.size(), 0, inuse);

  cout << ans.size() << "\n";
  for(auto s : ans){
    cout << s << "\n";
  }
  return 0;
}