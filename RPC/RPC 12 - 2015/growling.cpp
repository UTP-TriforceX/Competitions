#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

struct terna{
	double a;
	double b;
	double c;
	terna(){}
	terna(double _a, double _b, double _c): a(_a), b(_b), c(_c){}
};

double f(double a, double b, double c, double r){
	return -a*r*r + b*r + c;
}

double f2(double a, double b, double r){
	return -2*a*r + b;
}

//FORMA 1
/*double binarySearch(double a, double b, double c){
	double low = 0, hi = 10000*3, mid;
	while(fabs(low - hi) > EPS){
		mid = (low+hi)/2;
		if(f2(a,b,mid) >= EPS){
			low = mid;
		}
		else
			hi = mid;
	}

	return f(a,b,c,low);

}*/

//FORMA 2
int solve(double a, double b, double c){
	double r = b/(2*a);
	return f(a,b,c,r);
}

int main(){
	int t, ecu;
	cin>>t;
	while(t--){
		vector <terna> tri;
		int index;
		double a, b, c, ans = -1;
		cin>>ecu;
		for(int i=0; i<ecu; i++){
			cin>>a>>b>>c;
			tri.push_back(terna(a,b,c));
		}
		for(int i=0; i<tri.size(); i++){
			if(solve(tri[i].a,tri[i].b,tri[i].c) > ans){
				ans = solve(tri[i].a,tri[i].b,tri[i].c);
				index = i;
			}
		}
		cout<<index+1<<endl;
	}
	return 0;
}