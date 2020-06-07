#include<bits/stdc++.h>

using namespace std;
int main(){
	int s, c, u, v, passed;
	cin >> s;
	vector< pair<int, int> > holes(s);

	for(int i = 0; i < s; i++) cin >> holes[i].first >> holes[i].second;

	cin >> c;
	passed = 0;
	int cuantoPaso = 0;
	int ultimaPos = -1;
	while(c--){
		cin >> u >> v;
		if(ultimaPos == -1){
			for(int i = 0; i < s; i++){
				passed++;
				if(u <= holes[i].first && v >= holes[i].second){ 
					ultimaPos = i;
					cuantoPaso = passed;
					break;
				}
			}
		}
		else{
			int newPasos = 0;
			if(u > holes[ultimaPos].first || v < holes[ultimaPos].second){
				passed += cuantoPaso;
				for(int i = ultimaPos + 1; i < s; i++){
					newPasos++;
					if(u <= holes[i].first && v >= holes[i].second){
						ultimaPos = i;
						passed += newPasos;
						cuantoPaso = newPasos + cuantoPaso;
						break;
					}
				}
			}
			else{
				for(int i = 0; i < s; i++){
					newPasos++;
					if(u <= holes[i].first && v >= holes[i].second){ 
						ultimaPos = i;
						passed+= newPasos;
						cuantoPaso = newPasos;
						break;
					}
				}
			}
		}
	}
	cout << passed << "\n";
	return 0;
}