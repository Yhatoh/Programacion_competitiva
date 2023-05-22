#include <bits/stdc++.h>
using namespace std;

void apply_modifiers(int* success, int* total, vector<string>& dices, int index, int d, int amount){
  if(index == dices.size()){
    (*total)++;
    if(amount >= d) (*success)++;
    return;
  }

  // [+-]dx -> 3 4 5 6 7 8 9 10
  char op = dices[index][0];
  int num = 0;
  if(dices[index].length() == 4){
    num = 10;
  } else {
    num = dices[index][2] - '0';
  }

  for(int i = 1; i <= num; i++){
    if(op == '+'){
      apply_modifiers(success, total, dices, index + 1, d, amount + i);
    } else if(op == '-') {
      apply_modifiers(success, total, dices, index + 1, d, amount - i);
    }
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(6); 

  int d, m;
  cin >> d >> m;

  string stat;
  cin >> stat;

  int k;
  cin >> k;
  vector<string> dices(k);
  for(int i = 0; i < k; i++){
    cin >> dices[i];
  }

  int success = 0;
  int total = 0;
  for(int i = 1; i <= 20; i++){
    if(stat.compare("straight") == 0){
      if(i == 1){
        total++;
        continue;
      }

      if(i == 20){
        total++;
        success++;
        continue;
      }

      apply_modifiers(&success, &total, dices, 0, d, i + m);
    } else {
      for(int j = 1; j <= 20; j++){
        int real;
        if(stat.compare("advantage") == 0){
          real = max(j, i);
        } else {
          real = min(j, i);
        }

        if(real == 1){
          total++;
          continue;
        }

        if(real == 20){
          total++;
          success++;
          continue;
        }
        
        apply_modifiers(&success, &total, dices, 0, d, real + m);
        
      }
    }
  }
  cout << (double) success / (double) total << "\n";
  return 0;
}