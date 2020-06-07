#include <bits/stdc++.h>
using namespace std;


typedef pair <int,int> ii;
typedef pair< ii, int> iasd;
typedef pair< int, ii> iasd2;
typedef vector< iasd2 > iis2;
typedef vector< iasd > iis;

int main(){
	int t, n, i, a, b, h;
	
	cin >> t;
	h = 0;
	while(h < t){
		cin >> n;
		iis2 c;
		iis2 j;
		iis horarios;
		ii horario;

		iasd que;
		iasd2 queque;
		for(i = 0; i < n; i++){
			cin >> a >> b;

			horario.first = a;
			horario.second = b;
			que.second = i;
			que.first = horario;
			horarios.push_back(que);
		}
		sort(horarios.begin(), horarios.end());

		a = 0;
		for(i = 0; i < n; i++){
			queque.first = horarios[i].second;
			queque.second.first = horarios[i].first.first;
			queque.second.second = horarios[i].first.second;

			if(c.size() == 0) c.push_back(queque);
			else{
				if(c[c.size() - 1].second.second <= horarios[i].first.first) c.push_back(queque);
				else if(j.size() == 0) j.push_back(queque);
				else{
					if(j[j.size() - 1].second.second <= horarios[i].first.first) j.push_back(queque);
					else {a = 1; break;}
				}
			}
		}
		sort(j.begin(), j.end());
		sort(c.begin(), c.end());

		h++;
		if(a) cout << "Case #" << h << ": IMPOSSIBLE\n";
		else{

			cout << "Case #" << h << ": ";
			i = 0;
			b = 0;
			while(i < c.size() && b < j.size()){
				if(c[i].first < j[b].first) {cout << "C"; i++;}
				else{cout << "J"; b++;}
			}

			while(i < c.size()){ 
				cout << "C";
				i++;
			}
			while(b < j.size()){ 
				cout << "J";
				b++;
			}
			cout << "\n";

		}
		
	}

	return 0;
}