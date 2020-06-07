#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r;
	cin >> a;
	b = 0;
	while(b < a){
		//15
		vector< vector<int> > wall(9);
		cin >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m >> n >> o >> p >> q;
		wall[0].push_back(c);
		wall[1].push_back(0);
		wall[1].push_back(0);
		wall[2].push_back(d);
		wall[2].push_back(0);
		wall[2].push_back(e);
		for(r = 0; r < 4; r++) wall[3].push_back(0);
		wall[4].push_back(f);
		wall[4].push_back(0);
		wall[4].push_back(g);
		wall[4].push_back(0);
		wall[4].push_back(h);	
		for(r = 0; r < 6; r++) wall[5].push_back(0);
		wall[6].push_back(i);
		wall[6].push_back(0);
		wall[6].push_back(j);
		wall[6].push_back(0);
		wall[6].push_back(k);
		wall[6].push_back(0);
		wall[6].push_back(l);
		for(r = 0; r < 8; r++) wall[7].push_back(0);
		wall[8].push_back(m);
		wall[8].push_back(0);
		wall[8].push_back(n);
		wall[8].push_back(0);
		wall[8].push_back(o);
		wall[8].push_back(0);
		wall[8].push_back(p);
		wall[8].push_back(0);
		wall[8].push_back(q);
		b++;

		wall[2][1] = (wall[0][0]-(wall[2][0]+wall[2][2]))/2;
		wall[1][0] = wall[2][1] + wall[2][0];
		wall[1][1] = wall[2][1] + wall[2][2];

		wall[4][1] = (wall[2][0]-(wall[4][0]+wall[4][2]))/2;
		wall[3][0] = wall[4][1] + wall[4][0];
		wall[3][1] = wall[4][1] + wall[4][2];
		wall[4][3] = (wall[2][2]-(wall[4][2]+wall[4][4]))/2;
		wall[3][2] = wall[4][3] + wall[4][2];
		wall[3][3] = wall[4][3] + wall[4][4];

		wall[6][1] = (wall[4][0]-(wall[6][0]+wall[6][2]))/2;
		wall[5][0] = wall[6][0] + wall[6][1];
		wall[5][1] = wall[6][2] + wall[6][1];
		wall[6][3] = (wall[4][2]-(wall[6][4]+wall[6][2]))/2;
		wall[5][2] = wall[6][2] + wall[6][3];
		wall[5][3] = wall[6][4] + wall[6][3];
		wall[6][5] = (wall[4][4]-(wall[6][4]+wall[6][6]))/2;
		wall[5][4] = wall[6][4] + wall[6][5];
		wall[5][5] = wall[6][6] + wall[6][5];	

		wall[8][1] = (wall[6][0]-(wall[8][0]+wall[8][2]))/2;
		wall[7][0] = wall[8][0] + wall[8][1];
		wall[7][1] = wall[8][2] + wall[8][1];
		wall[8][3] = (wall[6][2]-(wall[8][4]+wall[8][2]))/2;
		wall[7][2] = wall[8][2] + wall[8][3];
		wall[7][3] = wall[8][4] + wall[8][3];
		wall[8][5] = (wall[6][4]-(wall[8][4]+wall[8][6]))/2;
		wall[7][4] = wall[8][4] + wall[8][5];
		wall[7][5] = wall[8][6] + wall[8][5];
		wall[8][7] = (wall[6][6]-(wall[8][6]+wall[8][8]))/2;
		wall[7][6] = wall[8][6] + wall[8][7];
		wall[7][7] = wall[8][8] + wall[8][7];
		
		cout << wall[0][0] << "\n";
		cout << wall[1][0] << " " << wall[1][1] << "\n";
		cout << wall[2][0] << " " << wall[2][1] << " " << wall[2][2] << "\n";
		cout << wall[3][0] << " " << wall[3][1] << " " << wall[3][2] << " " << wall[3][3] << "\n";
		cout << wall[4][0] << " " << wall[4][1] << " " << wall[4][2] << " " << wall[4][3] << " " << wall[4][4] << "\n";
		cout << wall[5][0] << " " << wall[5][1] << " " << wall[5][2] << " " << wall[5][3] << " " << wall[5][4] << " " << wall[5][5] << "\n";
		cout << wall[6][0] << " " << wall[6][1] << " " << wall[6][2] << " " << wall[6][3] << " " << wall[6][4] << " " << wall[6][5] << " " << wall[6][6] << "\n";
		cout << wall[7][0] << " " << wall[7][1] << " " << wall[7][2] << " " << wall[7][3] << " " << wall[7][4] << " " << wall[7][5] << " " << wall[7][6] << " " << wall[7][7] << "\n";
		cout << wall[8][0] << " " << wall[8][1] << " " << wall[8][2] << " " << wall[8][3] << " " << wall[8][4] << " " << wall[8][5] << " " << wall[8][6] << " " << wall[8][7] << " " << wall[8][8] << "\n";
	
	}
	return 0;
}