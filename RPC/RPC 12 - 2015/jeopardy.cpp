#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector < pair<int, int> > points;
char dir[4] = {'N', 'S', 'E', 'O'};
char move[4] = {'F', 'R', 'L', 'B'};
int x[4][4] = {{0, 0, 1, -1},
			   {1, -1, 0, 0},
			   {-1, 1, 0, 0}, 
			   {0, 0, -1, 1}};

int y[4][4] = {{1, -1, 0, 0}, 
			   {0, 0, -1, 1},
			   {0, 0, 1, -1},
			   {-1, 1, 0, 0}};


void make(string &path){
	char cur = 'E';
	int maxN = 0;
	int minS = 0;
	int maxE = 0;
	pair<int, int> p(0, 0);
	points.push_back(p);
	for (int i = 0; i < path.size(); ++i){
		for (int j = 0; j < 4; ++j){
			for(int k = 0; k < 4; ++k){
				if(path[i] == move[j] && cur == dir[k]){
					p.first = p.first + x[j][k];
					p.second = p.second + y[j][k];
					char tmp = cur;
					if(tmp == 'E' && path[i] == 'R') {cur = 'S';}
					else if (tmp == 'E' && path[i] == 'L') cur = 'N';
					else if (tmp == 'E' && path[i] == 'B') cur = 'O';
					else if (tmp == 'O' && path[i] == 'R') cur = 'N';
					else if (tmp == 'O' && path[i] == 'L') cur = 'S';
					else if (tmp == 'O' && path[i] == 'B') cur = 'E';
					else if (tmp == 'N' && path[i] == 'R') cur = 'E';
					else if (tmp == 'N' && path[i] == 'L') cur = 'O';
					else if (tmp == 'N' && path[i] == 'B') cur = 'S';
					else if (tmp == 'S' && path[i] == 'R') cur = 'O';
					else if (tmp == 'S' && path[i] == 'L') cur = 'E';
					else if (tmp == 'S' && path[i] == 'B') cur = 'N';

					if(p.first > maxE) maxE = p.first;
					if(p.second > maxN && p.second > 0) maxN = p.second;
					if(p.second < minS && p.second < 0) minS = p.second;
					points.push_back(p);
					break;
				}
			}
		}
	}

	//building matrix

	int dimX = 2 + maxE;
	int dimY = 3 + (maxN + fabs(minS));
	
	char matrix[dimY][dimX];
	memset(matrix, '#', sizeof(matrix));

	for (int i = 0; i < points.size(); ++i){

		matrix[points[i].second + abs(minS) + 1][points[i].first] = '.';
	}

	cout<<dimY<<" "<<dimX<<endl;
	for (int i = dimY-1; i >=0; i--){
		for (int j = 0; j < dimX; ++j){
			cout<<matrix[i][j];
		}
		cout<<endl;
	}
}

int main(){
	int cases; cin>>cases;
	cout<<cases<<endl;
	while(cases--){
		string s; cin>>s;
		points.clear();
		make(s);
	}
	return 0;
}