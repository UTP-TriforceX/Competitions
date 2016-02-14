#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int ans[3][3] = {{1,4,11},{4,64,1392},{11,1392,389497}};
	int n,m,cont=0;
	while(cin>>n>>m && n && m){
		int solve = 0;
		cont++;
		n--;m--;
		if(n <= 2 &&  m <= 2)solve = ans[n][m];
		cout<<"Case #"<<cont<<": "<<solve<<endl;
	}
	return 0;
}