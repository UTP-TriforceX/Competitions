#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define D(x) cout << #x "=" << x << endl
#define PI acos(-1)

using namespace std;

int main() {
  fast;
  double a, b;

  while (cin >> a >> b) {
  	double d = a - b, r = a + b;
  	double theta = 2 * acos(d / r);
  	double ans = ((r * r) / 2 * (theta - sin(theta))) - (PI * b * b);
  	cout << fixed << setprecision(3) << ans << endl;
  }

  return 0;
}