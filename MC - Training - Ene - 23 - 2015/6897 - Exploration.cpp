#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
  fast;
  int t, n, k, f, u, v, ans, count = 0;
  cin >> t;

  while (t--) {
    cin >> n >> k >> f;
    ans = count = 0;
    vector<set<int> > friends(n + 1);
    vector<int> groups(n + 1, 0);

    while (f--) {
      cin >> u >> v;
      friends[u].insert(v);
      friends[v].insert(u);
    }

    for (int i = 1; i <= n; i++) {
      for (auto &it : friends[i]) {
        count = 0;
        for (auto &itt : friends[it]) {
          if (friends[i].count(itt) or itt == i) count++;
        }
        if (count >= k) groups[i]++;
      }
    }

    for (int i = 1; i <= n; i++) ans = max(ans, groups[i] + 1);
    cout << ((ans >= k)? ans : 0) << endl;
  }
  return 0;
}
