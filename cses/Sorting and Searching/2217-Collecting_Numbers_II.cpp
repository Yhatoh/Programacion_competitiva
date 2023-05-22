#include<bits/stdc++.h>
using namespace std;


int main(){
  int n, m;
  cin >> n >> m;
  vector< int > nums(n);
  vector< int > ind(n);
  for (int i = 0; i < n; ++i){
    cin >> nums[i];
    nums[i]--;
    ind[nums[i]] = i;
  }

  int rounds = 1;
  int ind_act = ind[0];
  for(int i = 1; i < n; i++){
    if(ind_act == -1){
      rounds++;
    } else if(ind_act > ind[i]){
      rounds++;
    }
    ind_act = ind[i];
  }

  while(m--){
    int a, b;
    cin >> a >> b;

    a--;
    b--;

    int num_a = nums[a];
    int num_b = nums[b];
    int prev_num_a = num_a - 1;
    int prev_num_b = num_b - 1;
    int next_num_a = num_a + 1;
    int next_num_b = num_b + 1;

    nums[a] = num_b;
    nums[b] = num_a;

    if(prev_num_a != -1){
      if(ind[prev_num_a] <= ind[num_a] && ind[prev_num_a] > b) rounds++;
      else if(ind[prev_num_a] > ind[num_a] && ind[prev_num_a] <= b) rounds--;
    }

    if(next_num_a != n){
      if(ind[next_num_a] >= ind[num_a] && ind[next_num_a] < b) rounds++;
      else if(ind[next_num_a] < ind[num_a] && ind[next_num_a] >= b) rounds--;
    }

    ind[num_a] = b;

    if(prev_num_b != -1){
      if(ind[prev_num_b] <= ind[num_b] && ind[prev_num_b] > a) rounds++;
      else if(ind[prev_num_b] > ind[num_b] && ind[prev_num_b] <= a) rounds--;
    }

    if(next_num_b != n){
      if(ind[next_num_b] >= ind[num_b] && ind[next_num_b] < a) rounds++;
      else if(ind[next_num_b] < ind[num_b] && ind[next_num_b] >= a) rounds--;
    } 

    ind[num_b] = a;

    cout << rounds << "\n";
  }
  return 0;
}