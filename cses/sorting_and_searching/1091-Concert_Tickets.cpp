#include<bits/stdc++.h>
using namespace std;

bool reve(int a, int b){
  return a > b;
}

bool reve2(pair< int, int > a, pair< int, int > b){
  if(a.first != b.first)
    return a.first > b.first;


    return a.second < b.second;

}

int main(){
  int n, m;
  cin >> n >> m;

  multiset< int, greater< int >> tickets;
  
  for (int i = 0; i < n; ++i){
    int ticket;
    cin >> ticket;
    tickets.insert(ticket);
  }
  
  for (int i = 0; i < m; ++i){
    int customer;
    cin >> customer;

    auto x = tickets.lower_bound(customer);
    if(x != tickets.end()){
      cout << *x << "\n";
      tickets.erase(x);
    } else cout << "-1\n";
  }
  return 0;
}