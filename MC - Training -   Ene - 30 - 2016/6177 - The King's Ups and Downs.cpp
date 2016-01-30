#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;
typedef long long ll;

vector<ll> ans(22);

void calc() {
  vector<vector<ll> > memo(22, vector<ll> (22, 0));
  memo[1][1] = 1;
  ans[1] = 1;

  for (int num = 2; num < 21; num++) {
    for (int index = 2; index <= num; index++) {
      memo[num][index] = memo[num - 1][num + 1 - index] + memo[num][index - 1];
      ans[num] += memo[num][index];
    }
    // Se incluye la posibilidad en el otro sentido (ej: 123, 321)
    ans[num] <<= 1;
  }
}

int main() {
  fast;
  calc();
  int t, nc, n;
  cin >> t;

  while (t--) {
    cin >> nc >> n;
    cout << nc << " " << ans[n] << endl;
  }
  return 0;
}
