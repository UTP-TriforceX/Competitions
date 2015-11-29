#include <bits/stdc++.h>

//11137 - Ingenuous Cubrency: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2078

using namespace std;

long long cubes[21] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
long long memo[21][10005];
long long n;

//Forma recursiva
long long DP(int index, long long acum){
	if(index >= 21) return 0LL;
	if(memo[index][acum] != -1) return memo[index][acum];

	long long ans1 = 0LL, ans2 = 0LL;

	if(acum - cubes[index] == 0) ans1 = 1LL;
	else if(acum - cubes[index] > 0) ans1 = DP(index, acum - cubes[index]);
	if(acum - cubes[index] >= 0) ans2 = DP(index+1, acum);

	return memo[index][acum] = ans1 + ans2;
}

//Forma Iterativa
long long ways [10005];
void count (){
    ways [0] = 1;
    for (int index = 0; index < 21; index++ ){
        for (int acum = cubes [index]; acum < 10005; acum++)
            ways [acum] += ways [acum - cubes [index]];
    }
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//count();
	memset(memo,-1,sizeof(memo));
	while(cin>>n){
		cout<<DP(0,n)<<endl;
		//cout<<ways[n]<<endl;
	}
	return 0;
}