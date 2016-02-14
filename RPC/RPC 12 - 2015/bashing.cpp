#include <bits/stdc++.h>
#define OO 3600 * 3600 + 4

using namespace std;

int n,t;

int check(int pressed) {
	int aux = min(pressed, 3600);
  	return max(0, aux);
}

pair<int, int> BFS(vector<int> &G){
	queue <int> q;
	vector<int> distance(3601, OO);
	q.push(0);
	distance[0] = 0;

	while(!q.empty()){
		int current = q.front();
		q.pop();
		if(distance[current] < OO){
			for(int i=0; i<G.size(); i++){
				int cbuttom = distance[current] + 1; //Distancia del boton oprimido
				int newbuttom =  check(current + G[i]); //Se genera un nuevo boton
				if(cbuttom < distance[newbuttom]){ //verificamos si la distancia del boton previo es menor a la del nuevo boton
					distance[newbuttom] = cbuttom;
					q.push(newbuttom);
				}
			}
		}
	}

	for(int i=t; i<3601; i++){
		if(distance[i] < OO) return make_pair(distance[i], i-t);
	}
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(NULL);
	int cases;
	cin>>cases;
	while(cases--){
		cin>>n>>t;
		vector <int>G(n);
		for(int i=0; i<n; i++)cin>>G[i];
		sort(G.rbegin(),G.rend());
		pair<int,int> ans = BFS(G);
		cout<<ans.first<<" "<<ans.second<<endl;
	}
	return 0;
}