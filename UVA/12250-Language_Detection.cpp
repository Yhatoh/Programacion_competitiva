#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	string test;
	string esp = "HOLA";
	string ing = "HELLO";
	string ger = "HALLO";
	string fre = "BONJOUR";
	string ita = "CIAO";
	string rus = "ZDRAVSTVUJTE";
	cin >> test;
	int i = 1;
	while(test.compare("#") != 0){
		if(test.compare(esp) == 0) cout << "Case " << i << ": SPANISH" << "\n";
		else if(test.compare(ing) == 0) cout << "Case " << i << ": ENGLISH" << "\n";
		else if(test.compare(ger) == 0) cout << "Case " << i << ": GERMAN" << "\n";
		else if(test.compare(fre) == 0) cout << "Case " << i << ": FRENCH" << "\n";
		else if(test.compare(ita) == 0) cout << "Case " << i << ": ITALIAN" << "\n";
		else if(test.compare(rus) == 0) cout << "Case " << i << ": RUSSIAN" << "\n";
		else cout << "Case " << i << ": UNKNOWN" << "\n";
		cin >> test;
		i++;
	}
	return 0;
}