#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

typedef long long ll;

double f(ll n) {
  double ans = n / (double)(n + 1);
  return ans;
}

int main() {
  fast;
  int n;
  ll l, r;
  cin >> n;

  while (n--) {
    cin >> l >> r;
    cout << fixed << setprecision(12) << f(r) - f(l - 1) << endl;
  }

  return 0;
}
