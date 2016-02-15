#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define EPS 1e-9

using namespace std;
typedef long long ll;

int main() {
  fast;
  int t;
  ll d, x, y, ans;
  long double dist;
  cin >> t;

  while (t--) {
    ans = 0LL;
    cin >> d >> x >> y;
    if (x or y) {
      dist = sqrt(x * x + y * y) / sqrt(d);
      ans = (ll)max(1.0L, floor(dist));
      (fabs(dist - floor(dist)) < EPS)? cout << ans : cout << ans + 1;
      cout << endl;
    }
    else {
      cout << 0 << endl;
    }
  }

  return 0;
}
