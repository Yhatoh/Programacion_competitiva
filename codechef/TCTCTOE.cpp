#include<bits/stdc++.h>

using namespace std;

int win(char player, vector< string > &lines) {
	int i;
	int timeWin = 0;
	for(i = 0; i < 3; i++){
		if(lines[i][0] == player && lines[i][1] == player && lines[i][2] == player)
			timeWin++;
		if(lines[0][i] == player && lines[1][i] == player && lines[2][i] == player)
			timeWin++;
	}

	if(lines[0][0] == player && lines[1][1] == player && lines[2][2] == player)
		timeWin++;
	if(lines[0][2] == player && lines[1][1] == player && lines[2][0] == player)
		timeWin++;

	return timeWin;
}

pair< int, int > cantXY(vector< string > &lines) {
	int i, j, x, o;

	x = o = 0;

	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(lines[i][j] == 'O')
				o++;
			else if(lines[i][j] == 'X')
				x++;
		}
	}

	return pair< int, int >{x, o};
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);

	int t;
	cin >> t;
	while(t--){
		vector< string > lines(3);
		cin >> lines[0];
		cin >> lines[1];
		cin >> lines[2];

		int winO = win('O', lines);
		int winX = win('X', lines);

		pair< int, int > xo = cantXY(lines);
		int x = xo.first;
		int o = xo.second;

		//cout << winO << " " << o << " " << winX << " " << x << "\n";
		if(x == o + 1 && x + o == 9 && winX == 2 && winO == 0)
			cout << "1\n";
		else if(winO > 1 || winX > 1)
			cout << "3\n";
		else if(winO == 1 && winX == 1)
			cout << "3\n";
		else if(!(x == o || x == o + 1))
			cout << "3\n";
		else if(winX == 1 && x != o + 1)
			cout << "3\n";
		else if(winO == 1 && x != o)
			cout << "3\n";
		else if(winX == 1)
			cout << "1\n";
		else if(winO == 1)
			cout << "1\n";
		else if(x + o == 9)
			cout << "1\n";
		else
			cout << "2\n";
	}
	return 0;
}
