#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
    int c,s,i,j,a,d,dif,max_dif,max_nota;
    vector<int> notas(100000);
    cin >> c;
    a = 0;
    while(a < c){
        cin >> s;
        max_dif = -100000000;
        max_nota = -100000000;
        for(i = 0; i < s; i++){
            cin >> j;
            notas[i] = j;
        }
        for(i = 0; i < s-1; i++){
            if(notas[i] >  max_nota) max_nota = notas[i];
            if(max_nota-notas[i+1] > max_dif) max_dif = max_nota-notas[i+1];
        }
        cout << max_dif << "\n";
        a++;
    }
    return 0;
}