#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, s, t, u, v;
  long long ans_count = 0;

  cin >> n >> m >> s >> t;
  vector< vector<int> > g(n, vector<int> ());
  long long state[n][t+1];
  memset(state, 0, sizeof(state));

  while (m--) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  state[s][0] = 1;
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j < n; j++) {
      if (state[j][i-1] > 0) {
        for (int k = 0; k < g[j].size(); k++) {
          state[g[j][k]][i] += state[j][i-1];
        }
      }
    }
  }


  for (int i = 0; i < n; i++) {
    ans_count += state[i][t];
  }

  cout << ans_count << endl;
  return 0;
}
