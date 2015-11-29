#include <bits/stdc++.h>

using namespace std;

int n;

int best(int u, int d){
	int a,b;
	a = floor((double)(n*d/(u+d)))+1;
	b = n - a;
	return a*u-b*d;
}

int main(){
	int m,u,d;
	while(cin>>n>>m){
		int ans = 1000000009;
		while(m--){
			cin>>u>>d;
			ans = min(ans, best(u,d));
		}
		cout<<ans<<endl;
	}
	return 0;
}