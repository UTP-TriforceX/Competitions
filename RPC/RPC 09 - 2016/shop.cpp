#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define N 505

using namespace std;

int n;
int memo[N][N];

int dp(int i, int acc, vector<int> &spree) {
  if (i == n) return 0;
  if (memo[i][acc] != -1) return memo[i][acc];

  int ans = dp(i + 1, acc, spree);
  if (i == 0 or (acc + 1) <= (i + 1) / 2) {
    ans = max(ans, dp(i + 1, acc + 1, spree) + spree[i]);
  }

  return memo[i][acc] = ans;
}

int main() {
  fast;
  int t, tc = 1;
  cin >> t;

  while (t--) {
    cin >> n;
    vector<int> spree(n);
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < n; i++) {
      cin >> spree[i];
    }
    cout << "Spree #" << tc++ << ": " << dp(0, 0, spree) << endl;
  }

  return 0;
}
