#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
    int n,l,c,cant_lineas_escritas,cant_char_escritos,cant_pag_escritas,k;
    string palabra;
    while(cin >> n >> l >> c){
        k = 0;
        cant_pag_escritas = 1;
        cant_char_escritos = cant_lineas_escritas = 0;
        while(k < n){
            cin >> palabra;

            if(palabra.size()+cant_char_escritos <= c){
                cant_char_escritos = palabra.size()+cant_char_escritos;
            }
            else{
                cant_lineas_escritas++;
                cant_char_escritos = palabra.size();
            }
            if(k != 0 || k != n-1) cant_char_escritos++;
            if(cant_lineas_escritas == l){
                cant_lineas_escritas = 0;
                cant_pag_escritas++;
            }
            k++;
        }
        cout << cant_pag_escritas << "\n";
    }
    return 0;
}