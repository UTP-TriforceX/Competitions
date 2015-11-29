#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k, casos = 0;
	while( cin >> n >> k && n + k){
		vector<pair<double,double> > go(n);
		
		for(int i = 0; i < n; i++) cin >> go[i].first >> go[i].second;
		
		sort(go.begin(), go.end());
		
		double sum = 0;
		double priceMax = -1, sizeMax = -1;
	
		for(int i = 0; i < k; i++) {
		 	sum += go[i].first;
		 	if(go[i].first > sizeMax) {
		 		sizeMax = go[i].first;
		 		priceMax = go[i].second;
		 	} else if (go[i].first == sizeMax)
		 		priceMax = max(priceMax, go[i].second);
		}
		
		double cost = sum * priceMax/sizeMax;
		for (int i = k; i < n; i++) {
			if (go[i].first == sizeMax)
				continue;
			double aux = sum - sizeMax;
			aux += go[i].first;
			aux *= go[i].second / go[i].first;
			
			cost = min(cost, aux);
		}
		
		
		cout << "Case #" << ++casos << ": " << fixed <<  setprecision(6) << cost << endl;
		
	}
}