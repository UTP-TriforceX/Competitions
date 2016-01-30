#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;
typedef long long ll;


int main() {
  fast;
  int t, nc, base;
  string s;
  cin >> t;

  while (t--) {
    ll ans = 0;
    cin >> nc >> base >> s;
    for (int i = 0; i < s.size(); i++) {
      ans += s[i] - '0';
    }
    cout << nc << " " << ans % (base - 1) << endl;
  }
  return 0;
}
