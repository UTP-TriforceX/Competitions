#include <bits/stdc++.h>

using namespace std;

long long toLong(string x){
	stringstream ss;
	ss << x;
	long long r;
	ss >> r;
	return r;
}

string toStr(long long x){
	stringstream ss;
	ss << x;
	return ss.str();
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(NULL);
	int cont = 0;
	string a,b;
	cin>>a;
	b = a;
	while(true){
		sort(a.begin(), a.end());
		cont++;
		if(toLong(b) - toLong(a) <= 0)break;
		b = toStr(toLong(b)-toLong(a));
		a = b;
	}
	cout<<cont<<endl;
	return 0;
}