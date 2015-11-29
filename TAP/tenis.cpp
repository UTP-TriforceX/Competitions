#include <bits/stdc++.h>

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
	int N = 0, s = 0, min_set = 0, dif = 0;
	int winA = 0, winB = 0;
	int setA = 0, setB = 0;
	string games;
	cin>>N>>s>>min_set>>dif;
	cin>>games;
	

	for (int i = 0; i < N; ++i)
	{
		if(games[i] == 'A'){
			winA++;
		}else if(games[i] == 'B'){
			winB++;
		}

		if(winA >= min_set || winB >= min_set){
			if(abs(winA-winB) >= dif){
				if(winA > winB){
					setA++;					
				}else{
					setB++;
				}
				winA = winB = 0;
			}
		}
	}

	cout<<setA<<" "<<setB<<endl;

	return 0;
}