#include<bits/stdc++.h>

using namespace std;
typedef map< int, vector <int> > graph;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r;
	cin >> a;
	vector <int> asoydown;
	pair<int, vector<int> > x;
	pair<int, int > x2;
	map <int, vector<int> >::iterator intento;
	map <int, int >::iterator intento2;
	map <int, int >::iterator intento3;
	o = 1;
	while(a != 0){
		graph dab;
		vector <int> test;
		b = 0;
		while(b < a){
			cin >> c >> d;
			intento = dab.find(c);
			if(intento == dab.end()){
				test.push_back(c);
				x = make_pair(c,asoydown);
				dab.insert(x);
			}
			intento = dab.find(c);
			intento->second.push_back(d);
			intento = dab.find(d);
			if(intento == dab.end()){
				test.push_back(d);
				x = make_pair(d,asoydown);
				dab.insert(x);
			}
			intento = dab.find(d);
			intento->second.push_back(c);
			b++;
		}
		/*
		cout << "GRAPH " << o << "\n";
		for(i = 0; i < test.size(); i++){
			intento = dab.find(test[i]);
			cout << intento->first << ":";
			for(j = 0; j < intento->second.size(); j++) cout << " " << intento->second[j];
			cout << "\n";
		}
		*/
		cin >> c >> d;
		while(c != 0 || d != 0){
			k = 0;
			map<int,int> dab2;
			for(i = 0; i < test.size(); i++){
				x2 = make_pair(test[i], 100);
				dab2.insert(x2);
			}
			intento2 = dab2.find(c);
			if(intento2 != dab2.end()){
				intento2->second = 0;
				queue<int>q;
				q.push(c);
				while(!q.empty()){
					int u = q.front();
					q.pop();
					intento = dab.find(u);
					intento3 = dab2.find(u);
					for(j = 0; j < intento->second.size(); j++){
						l = intento->second[j];
						intento2 = dab2.find(l);
						if(intento2->second == 100){
							intento2->second = intento3->second + 1;
							q.push(intento2->first);
						}
					}
				}
				for(j = 0; j < test.size(); j++){
					intento2 = dab2.find(test[j]);
					if(intento2->second > d) k++;
				}
				cout << "Case " << o << ": " << k << " nodes not reachable from node " << c << " with TTL = " << d << ".\n";
				o++;
			}
			else{
				cout << "Case " << o << ": " << test.size() << " nodes not reachable from node " << c << " with TTL = " << d << ".\n";
				o++;
			}
			cin >> c >> d;
		}
		cin >> a;
	}
	return 0;
}