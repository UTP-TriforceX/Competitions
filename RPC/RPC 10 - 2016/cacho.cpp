#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
  fast;
  int t;
  cin >> t;

  while (t--) {
    bool ok = true;
    vector<int> dices(5);
    for (int i = 0; i < 5; i++) cin >> dices[i];
    for (int i = 0; i < 4; i++) {
      if (dices[i] + 1 == dices[i + 1]) continue;
      ok = false;
    }
    cout << ((ok)? 'Y' : 'N') << endl;
  }

  return 0;
}
