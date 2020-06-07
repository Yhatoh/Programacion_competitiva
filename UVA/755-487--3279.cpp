#include<bits/stdc++.h>

using namespace std;

string code(char a){
	if(a == '0') return "0";
	else if(a == '1') return "1";
	else if(a == '2') return "2";
	else if(a == '3') return "3";
	else if(a == '4') return "4";
	else if(a == '5') return "5";
	else if(a == '6') return "6";
	else if(a == '7') return "7";
	else if(a == '8') return "8";
	else if(a == '9') return "9";
	else if(a == 'A' || a == 'B' || a == 'C') return "2";
	else if(a == 'D' || a == 'E' || a == 'F') return "3";
	else if(a == 'G' || a == 'H' || a == 'I') return "4";
	else if(a == 'J' || a == 'K' || a == 'L') return "5";
	else if(a == 'M' || a == 'N' || a == 'O') return "6";
	else if(a == 'P' || a == 'R' || a == 'S') return "7";
	else if(a == 'T' || a == 'U' || a == 'V') return "8";
	else if(a == 'W' || a == 'X' || a == 'Y') return "9";
}

bool stringc(const pair<string, int> &a, const pair<string, int> &b){
	return a.first > b.first;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	map<string, int> uff;
	char nani;
	int a,b,c,d,e,f,g,h,i,j,k,boi;
	string number;
	string number2;
	cin >> a;
	b = 0;
	while(b < a){
		if(b >= 1) cout << "\n";
		cin >> c;
		d = 0;
		e = 0;
		boi = 0;
		vector< pair < string, int> > duplicate(c);
		while(d < c){
			g = 0;
			cin >> number;
			number2 = "";
			if(d == 0){
				duplicate[0] = make_pair("",0);
				for(h = 0; h < number.size(); h++){
					if(number[h] != '-') duplicate[0].first = duplicate[0].first +code(number[h]);
				}
				uff.insert(pair<string,int>(duplicate[0].first,0));
				e++;
			}
			else{
				if(number[0] != '-') number2 = code(number[0]);
				for(i = 1; i < number.size(); i++){
					if(number[i] != '-') number2 = number2 + code(number[i]);
				}
				if(uff.find(number2) != uff.end()){
					boi = 1;
					duplicate[uff.find(number2)->second].second += 1;
				}
				else{
					duplicate[e] = make_pair(number2,0);
					uff.insert(pair<string,int>(duplicate[e].first,e));
					e++;
				}

			} 
			d++;
		}
		if(boi != 0){
			sort(duplicate.begin(),duplicate.end(),stringc);
			for(h = e; h >= 0; h--){
				if(duplicate[h].second != 0){
					for(i = 0; i < 7; i++){
						if(i != 2){
							cout << duplicate[h].first[i];
						}
						else cout << duplicate[h].first[i] << "-";
					}
					cout << " " << duplicate[h].second + 1 << "\n";
				}
			}
		}
		else cout << "No duplicates.\n";
		uff.clear();
		b++;
	}
	return 0;
}