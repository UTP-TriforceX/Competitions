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

int couting(string &s)
{
	int cVowel = 0, cCons = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			cVowel++;
		}else{
			cCons++;
		}
	}
	return (cVowel>cCons)? 1:0;

}

int main(){
	int a, b;
	int cases; cin>>cases;
	for (int caso = 0; caso < cases; ++caso)
	{
		string name;
		cin>>name;
		cout<<name<<"\n"<<couting(name)<<endl;
	}
	return 0;
}