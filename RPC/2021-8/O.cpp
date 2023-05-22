#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  vector< pair< int, string > >dogs(t);
  for (int i = 0; i < t; ++i)
  {
    cin >> dogs[i].second >> dogs[i].first;
  }

  sort(dogs.begin(), dogs.end());

  vector< string > dogi(3);
  dogi[0] = dogs[t - 1].second;
  dogi[1] = dogs[t - 2].second;
  dogi[2] = dogs[t - 3].second;

  sort(dogi.begin(), dogi.end());

  cout << dogi[0] << " " << dogi[1] << " " << dogi[2] << " " << dogs[t - 1].first * dogs[t - 2].first * dogs[t - 3].first << "\n";
  return 0;
}