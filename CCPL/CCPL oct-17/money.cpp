#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void dfs(int node,vector< vector<int> > &G, vector<bool> &visited, vector<int> &cost, int &cont){
	visited[node] = true;
	cont += cost[node];
	for(int i=0; i<G[node].size(); i++){
		int tmp = G[node][i];
		if(!visited[tmp])
			dfs(tmp,G,visited,cost,cont);
	}
}

int main(){
	int t;
	cin>>t;
	for (int k = 0; k < t; k++){
		int nodes, edges,a,b;
		bool flag = false;
		cin>>nodes>>edges;
		vector<int> cost(nodes);
		for(int i=0; i<nodes; i++)cin>>cost[i];
		vector< vector<int> > G(nodes);
		vector<bool> visited(nodes,false);
		for(int i=0; i<edges; i++){
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int i=0; i<nodes; i++){
			if(!visited[i]){
				int cont = 0;
				dfs(i,G,visited,cost,cont);
				if(cont != 0){
					flag = true;
					break;
				}
			}
		}
		(flag)? cout<<"IMPOSSIBLE\n" : cout<<"POSSIBLE\n";

	}
	return 0;
}