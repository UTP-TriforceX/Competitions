#include <bits/stdc++.h>
#define pi 3.1415926535897932384626433832795
#define EPS 1e-10

using namespace std;

const double R = 6371009.00 ; // radius of earth / sphere

// great Circle in Sphere / points must be in radian / distance between 2 pnts on earth
double spherical_distance(double lat1,double lon1,double lat2,double lon2) {
       double dlon = lon2 - lon1;
       double dlat = lat2 - lat1;
       double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
       double c = 2 * atan2(sqrt(a), sqrt(1-a));
       double d = R * c;
       double e = sqrt(2.*R*R *(1-cos(c)));
       return round(d-e+EPS);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		double ax,ay,bx,by;
		cin>>ax>>ay>>bx>>by;
		ax *= pi/180;
		ay *= pi/180;
		bx *= pi/180;
		by *= pi/180;
		long long ans = (long long)(0.5 + spherical_distance(ax,ay,bx,by));
		cout<<ans<<endl; 
	}
	return 0;
}

