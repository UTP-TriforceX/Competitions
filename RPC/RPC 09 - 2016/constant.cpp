#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'

using namespace std;

typedef long long ll;
ll memo[9][205];
int n;

ll dp(int index, int result, vector<int> &constants) {
  if (index == 8) return result == n;
  if (memo[index][result] != -1) return memo[index][result];

  ll ans = dp(index + 1, result, constants);
  for (int i = 1; result + constants[index] * i <= n; i++) {
    ans += dp(index + 1, result + constants[index] * i, constants);
  }

  return memo[index][result] = ans;
}

int main() {
  fast;
  int t, tc = 1;
  cin >> t;

  while (t--) {
    vector<int> constants(8);
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < 8; i++) {
      cin >> constants[i];
    }

    cin >> n;
    cout << "Equation #" << tc++ << ": " << dp(0, 0, constants) << endl;
  }

  return 0;
}
