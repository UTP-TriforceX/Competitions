#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAXN 500005


using namespace std;

typedef long long ll;

// // unordered_map<int, vector<ll>> divisors;
// vector<ll> divisors(MAXN);
//
// void divs() {
//   for (int i = 1; i < MAXN; i++) {
//     for (int j = i; j < MAXN; j += i) {
//       // divisors[j].push_back(i);
//       divisors[j] += i;
//     }
//   }
// }

ll divs(int n, int k) {
  ll ans = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i % k != 0) ans += i;
      if (i * i < n and (n / i) % k != 0) ans += (n / i);
    }
  }
  return ans;
}

int main() {
  fast;
  int t, n, k;
  cin >> t;

  while (t--) {
    cin >> n >> k;
    cout << divs(n, k) << endl;
  }

  return 0;
}
