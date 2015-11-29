#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int p[1008];
vector<long long> child(1008,0);
vector<long long> countNode(1008,0);
vector<long long> countEdge(1008,0);
set<int> parent;

int find_set(int x){
	if( x == p[x]) return x;
	return p[x] = find_set(p[x]);
}

void union_set(int x, int y){
	int px = find_set(x);
	int py = find_set(y);
	if(px == py) return;
	p[px] = py;
}

void init(int n){
	for(int i=0; i<n; i++)
		p[i] = i;
}

long long solve(int nodes, int ruta, int estadio){
	long long ans = 0;
	set<int>::iterator it;

	for(it = parent.begin(); it != parent.end(); ++it){
		long long aux = *it;
		long long edge = countEdge[aux]/2;
		long long node = countNode[aux];

		ans += min((((node*(node-1))/2)-edge)*ruta, node*estadio);
	}

	return ans;
}

int main(){
	fast;
	
	int nodes,edges,ruta,estadio,a,b,index = 0;
	long long ans = 0;
	cin>>nodes>>edges>>ruta>>estadio;
	init(nodes);

	for(int i=0; i<edges; i++){
		cin>>a>>b;
		a--;b--;
		child[a]++; //Contando aristas
		child[b]++; //Contando aristas
		union_set(a,b);
	}

	for(int i=0; i<nodes; i++){
		index = find_set(i);
		parent.insert(index);
		countNode[index]++; //Contando Nodos
	}

	for(int i=0; i<nodes; i++){
		countEdge[find_set(i)] += child[i];
	}

	ans = solve(nodes,ruta,estadio);
	cout<<ans<<endl;

	return 0;
}