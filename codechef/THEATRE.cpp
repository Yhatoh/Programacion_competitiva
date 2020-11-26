#include<bits/stdc++.h>

using namespace std;

int showtime[4][4];

void valueZero(){
	int i, j;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++) showtime[i][j] = 0;
	}
}

void sumOne(int i, int t){
	if(t == 12) showtime[i][0] += 1;
	else if(t == 3) showtime[i][1] += 1;
	else if(t == 6) showtime[i][2] += 1;
	else showtime[i][3] += 1;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);

	int T, n, t, i, j, count, max, total;
	char m;

	cin >> T;
	total = 0;
	while(T--){
		valueZero();

		cin >> n;
		for(i = 0; i < n; i++){
			cin >> m >> t;
			if(m == 'A') sumOne(0, t);
			else if(m == 'B') sumOne(1, t);
			else if(m == 'C') sumOne(2, t);
			else sumOne(3, t);
		}
		/*
		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++) cout << showtime[i][j] << " ";
			cout << "\n";
		}
		*/
		vector< vector< int > > combinations(24);

	//A first
		combinations[0].push_back(showtime[0][0]);
			//B Second
			combinations[0].push_back(showtime[1][1]);
				//C Third
				combinations[0].push_back(showtime[2][2]);
					//D Four
					combinations[0].push_back(showtime[3][3]);
		combinations[1].push_back(showtime[0][0]);
			//B Second
			combinations[1].push_back(showtime[1][1]);
				//D Third
				combinations[1].push_back(showtime[3][2]);
					//C Four
					combinations[1].push_back(showtime[2][3]);
		combinations[2].push_back(showtime[0][0]);
			//C Second
			combinations[2].push_back(showtime[2][1]);
				//B Third
				combinations[2].push_back(showtime[1][2]);
					//D Four
					combinations[2].push_back(showtime[3][3]);
		combinations[3].push_back(showtime[0][0]);
			//C Second
			combinations[3].push_back(showtime[2][1]);
				//D Third
				combinations[3].push_back(showtime[3][2]);
					//B Four
					combinations[3].push_back(showtime[1][3]);
		combinations[4].push_back(showtime[0][0]);
			//D Second
			combinations[4].push_back(showtime[3][1]);
				//B Third
				combinations[4].push_back(showtime[1][2]);
					//C Four
					combinations[4].push_back(showtime[2][3]);
		combinations[5].push_back(showtime[0][0]);
			//D Second
			combinations[5].push_back(showtime[3][1]);
				//C Third
				combinations[5].push_back(showtime[2][2]);
					//B Four
					combinations[5].push_back(showtime[1][3]);

	//B first
		combinations[6].push_back(showtime[1][0]);
			//A Second
			combinations[6].push_back(showtime[0][1]);
				//C Third
				combinations[6].push_back(showtime[2][2]);
					//D Four
					combinations[6].push_back(showtime[3][3]);
		combinations[7].push_back(showtime[1][0]);
			//A Second
			combinations[7].push_back(showtime[0][1]);
				//D Third
				combinations[7].push_back(showtime[3][2]);
					//C Four
					combinations[7].push_back(showtime[2][3]);
		combinations[8].push_back(showtime[1][0]);
			//C Second
			combinations[8].push_back(showtime[2][1]);
				//A Third
				combinations[8].push_back(showtime[0][2]);
					//D Four
					combinations[8].push_back(showtime[3][3]);
		combinations[9].push_back(showtime[1][0]);
			//C Second
			combinations[9].push_back(showtime[2][1]);
				//D Third
				combinations[9].push_back(showtime[3][2]);
					//A Four
					combinations[9].push_back(showtime[0][3]);
		combinations[10].push_back(showtime[1][0]);
			//D Second
			combinations[10].push_back(showtime[3][1]);
				//A Third
				combinations[10].push_back(showtime[0][2]);
					//C Four
					combinations[10].push_back(showtime[2][3]);
		combinations[11].push_back(showtime[1][0]);
			//D Second
			combinations[11].push_back(showtime[3][1]);
				//C Third
				combinations[11].push_back(showtime[2][2]);
					//A Four
					combinations[11].push_back(showtime[0][3]);

	//C first
		combinations[12].push_back(showtime[2][0]);
			//A Second
			combinations[12].push_back(showtime[0][1]);
				//B Third
				combinations[12].push_back(showtime[1][2]);
					//D Four
					combinations[12].push_back(showtime[3][3]);
		combinations[13].push_back(showtime[2][0]);
			//A Second
			combinations[13].push_back(showtime[0][1]);
				//D Third
				combinations[13].push_back(showtime[3][2]);
					//B Four
					combinations[13].push_back(showtime[1][3]);
		combinations[14].push_back(showtime[2][0]);
			//B Second
			combinations[14].push_back(showtime[1][1]);
				//A Third
				combinations[14].push_back(showtime[0][2]);
					//D Four
					combinations[14].push_back(showtime[3][3]);
		combinations[15].push_back(showtime[2][0]);
			//B Second
			combinations[15].push_back(showtime[1][1]);
				//D Third
				combinations[15].push_back(showtime[3][2]);
					//A Four
					combinations[15].push_back(showtime[0][3]);
		combinations[16].push_back(showtime[2][0]);
			//D Second
			combinations[16].push_back(showtime[3][1]);
				//A Third
				combinations[16].push_back(showtime[0][2]);
					//B Four
					combinations[16].push_back(showtime[1][3]);
		combinations[17].push_back(showtime[2][0]);
			//D Second
			combinations[17].push_back(showtime[3][1]);
				//B Third
				combinations[17].push_back(showtime[1][2]);
					//A Four
					combinations[17].push_back(showtime[0][3]);
	
	//D first
		combinations[18].push_back(showtime[3][0]);
			//A Second
			combinations[18].push_back(showtime[0][1]);
				//B Third
				combinations[18].push_back(showtime[1][2]);
					//C Four
					combinations[18].push_back(showtime[2][3]);
		combinations[19].push_back(showtime[3][0]);
			//A Second
			combinations[19].push_back(showtime[0][1]);
				//C Third
				combinations[19].push_back(showtime[2][2]);
					//B Four
					combinations[19].push_back(showtime[1][3]);
		combinations[20].push_back(showtime[3][0]);
			//B Second
			combinations[20].push_back(showtime[1][1]);
				//A Third
				combinations[20].push_back(showtime[0][2]);
					//C Four
					combinations[20].push_back(showtime[2][3]);
		combinations[21].push_back(showtime[3][0]);
			//B Second
			combinations[21].push_back(showtime[1][1]);
				//C Third
				combinations[21].push_back(showtime[2][2]);
					//A Four
					combinations[21].push_back(showtime[0][3]);
		combinations[22].push_back(showtime[3][0]);
			//C Second
			combinations[22].push_back(showtime[2][1]);
				//A Third
				combinations[22].push_back(showtime[0][2]);
					//B Four
					combinations[22].push_back(showtime[1][3]);
		combinations[23].push_back(showtime[3][0]);
			//C Second
			combinations[23].push_back(showtime[2][1]);
				//B Third
				combinations[23].push_back(showtime[1][2]);
					//A Four
					combinations[23].push_back(showtime[0][3]);

		for(i = 0; i < 24; i++){
			sort(combinations[i].begin(), combinations[i].end());
		
			if(i == 0){
				if(combinations[i][3] == 0) max = -100 * 4;
				else if(combinations[i][2] == 0) max = 100 * combinations[i][3] - 100 * 3;
				else if(combinations[i][1] == 0) max = 100 * combinations[i][3] + 75 * combinations[i][2] - 100 * 2;
				else if(combinations[i][0] == 0) max = 100 * combinations[i][3] + 75 * combinations[i][2] + 50 * combinations[i][1] - 100;
				else max = 100 * combinations[i][3] + 75 * combinations[i][2] + 50 * combinations[i][1] + 25 * combinations[i][0];
				j = i;
			}
			else {
				if(combinations[i][3] == 0) count = -100 * 4;
				else if(combinations[i][2] == 0) count = 100 * combinations[i][3] - 100 * 3;
				else if(combinations[i][1] == 0) count = 100 * combinations[i][3] + 75 * combinations[i][2] - 100 * 2;
				else if(combinations[i][0] == 0) count = 100 * combinations[i][3] + 75 * combinations[i][2] + 50 * combinations[i][1] - 100;
				else count = 100 * combinations[i][3] + 75 * combinations[i][2] + 50 * combinations[i][1] + 25 * combinations[i][0];
				
				if(count > max){
					j = i;
					max = count;
				}
			}			
		}

		cout << max << "\n";
		total += max;
	}

	cout << total << "\n";

	return 0;
}