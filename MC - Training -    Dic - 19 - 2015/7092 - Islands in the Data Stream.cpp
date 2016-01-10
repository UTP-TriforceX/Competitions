#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int solve(vector<int> &island) {
  int ans = 0, low = 0, j = 0;
  for (int i = 1; i <= 10; ++i) {
    for (int j = 10; j >= 1; --j) {
      if (i > j)
        continue;
      int mmin = INT_MAX;
      for (int k = i; k <= j; ++k)
        mmin = min(mmin, island[k]);
      if (mmin > island[i - 1] and mmin > island[j + 1])
        ans++;
    }
  }
  return ans;
}

int main() {
  fast;
  int t, k;
  cin >> t;
  while (t--) {
    cin >> k;
    vector <int> island(12);
    for (int i = 0; i< 12; i++) cin >> island[i];
    cout << k << " " << solve(island) << endl;
  }
  return 0;
}
