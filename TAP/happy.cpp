#include <bits/stdc++.h>

using namespace std;

map<int, vector <int> > graph;
vector <bool> visited;

void dfs(int start, vector <bool> &visit, long long &n, long long &edge){
		if(visit[start])return;
		visit[start] = true;
		n++;
		for (int i = 0; i < graph[start].size(); ++i){
			edge++;
			dfs(graph[start][i], visit, n, edge);
		}
	
}

int main(){
	int nodes, edges, rutes, estadios;
	int a, b, ans = 0;
	cin>>nodes>>edges>>rutes>>estadios;
	for (int i = 0; i < edges; i++){	
		cin>>a>>b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	visited.assign(nodes, false);

	for (int i = 0; i < visited.size(); ++i){
		if(!visited[i]){
			long long node=0, edge=0;
			dfs(i, visited, node, edge);
			edge /= 2; //por lo que es no dirigido esta en doble sentido
			ans += min((((node*(node-1))/2)-edge)*rutes,node*estadios);
		}
		
		
	}
	cout<<ans<<endl;

	return 0;
}