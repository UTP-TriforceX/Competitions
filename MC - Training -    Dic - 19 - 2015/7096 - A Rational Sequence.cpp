#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
  fast;
  int t, id;
  char c;
  int p, q, tmp;
  cin >> t;
  while (t--) {
    cin >> id;
    cin >> p >> c >> q;
    tmp = 0;
    cout << id << " ";
    if (p == q) cout << "1/2" << endl;
    else {
      tmp = p / q;
      if (p < q) cout << q << "/" << (q - p) << endl;
      else cout << q << "/" << (q - p + 2 * tmp * q) << endl;
    }
  }
  return 0;
}
