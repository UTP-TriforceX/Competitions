#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int G[102][102];
char dominator[102][102];
int n;

void dfs(int u, vector<bool> &visited, vector <int> &hijos){
	visited[u] = true;
	hijos.push_back(u);
	dominator[0][u] = 'Y';
	for(int i=0; i<n; i++){
		if(G[u][i] == 1 && !visited[i]){
			dfs(i, visited, hijos);
		}
	}
}

void dfs2(int u, int forb,vector<bool> &visited){
	visited[u]  = true;
	for(int i=0; i<n; i++){
		if(G[u][i] == 1 && !visited[i] && i != forb){
			visited[i] = true;
			dfs2(i,forb, visited);
		}
	}
}

void lines(){
	cout<<"+";
	for(int i=0; i<(2*n)-1; i++)cout<<"-";
	cout<<"+\n";
}
	
void dif(vector<int> hijos, vector<bool> &visited2, int index){
	for(int i=0; i<hijos.size(); i++){
		if(!visited2[hijos[i]]){
			dominator[index][hijos[i]] = 'Y';
		}
	}
}

int main(){
	int t;
	cin>>t;
	for(int k=0; k<t; k++){
		cin>>n;
		vector<int> hijos;
		vector<bool> visited(n,false);
		memset(dominator,'N',sizeof(dominator));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>G[i][j];
			}
		}
		vector<bool> visited2;
		dfs(0,visited, hijos);
		for(int j=1; j<n; j++){
			visited2.assign(n,false);
			dfs2(0,j,visited2);
			dif(hijos,visited2, j);
		}
		
		cout<<"Case "<<k+1<<":\n";
		for(int i=0; i<n; i++){
			lines();
			for(int j=0; j<n; j++){
				cout<<"|"<<dominator[i][j];
			}
			cout<<"|\n";
		}
		lines();
	}
	return 0;
}