#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
	int h, w;
	while(cin>>h>>w){
		char ascii[h][w];
		double area = 0.0;
		bool open = false;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin>>ascii[i][j];
			}
		}
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if((ascii[i][j] == '/' || ascii[i][j] == '\\') and !open){
					open = true;
					area += 0.5;
				}
				else if((ascii[i][j] == '/' || ascii[i][j] == '\\' )and open){
					open = false;
					area += 0.5;
				}
				else{
					if(open){
						area += 1.0;
					}
				}
			}
		}
		cout<<area<<endl; 
	}
	return 0;
}