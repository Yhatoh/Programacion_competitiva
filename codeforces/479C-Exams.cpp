#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    vector< pair< int, int > > exams(n);
    for(int i = 0; i < n; i++) {
      cin >> exams[i].first >> exams[i].second;
    }
    sort(exams.begin(), exams.end()); 

    int days = (exams[0].first > exams[0].second ? exams[0].second : exams[0].first);
    for(int i = 1; i < n; i++) {
      if(days <= exams[i].second) {
        days = exams[i].second;
      } else {
        days = exams[i].first;
      }
    }
    cout << days << "\n";
  }
  return 0;
}
