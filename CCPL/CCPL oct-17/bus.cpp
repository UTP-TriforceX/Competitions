#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string toStr(int x){
	stringstream s;
	s << x;
	return s.str();
}

int toInt(string x){
	stringstream s;
	s << x;
	int r;
	s >> r;
	return r;
}

int main(){
	long long t, n;
	cin>>t;
	vector<long long> solve(31,0);
	for (int i=0; i<t; i++){
		cin>>n;
		solve[1] = 1;
		for(int i=2; i<31; i++){
			solve[i] = solve[i-1]*2+1;
		}
		cout<<solve[n]<<endl;

	}

	return 0;
}