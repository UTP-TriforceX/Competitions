#include <bits/stdc++.h>

using namespace std;


void sums(long long num){
	double l2 = log2(num);
	if(l2 - floor(l2) == 0)	cout << "IMPOSSIBLE"<<endl;
	else{
		long long sum = 0;
		for (long long j= 2; j <= num; j++){
			sum = ((j-1)*j)/2;
			double x = (double)(num-sum)/(double)(j);
			if( x - floor(x) == 0){
				cout <<(long long)x;
				for (long long k = 1; k < j; k++){
					cout <<" + "<<(long long)(x+k);
				}
				cout<<endl;
				break;
			}
		}
	}
}

int main(){
	int n;
	long int num;
	cin >> n;
	while(n--){
		cin >> num;	
		sums(num);
	}
	return 0;
}
	