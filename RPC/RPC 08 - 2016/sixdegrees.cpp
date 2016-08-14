#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

int id = 0;

int get_id(map<string, int> &m, string &a) {
  if (m.count(a)) return m[a];
  return m[a] = id++;
}

bool bfs(int s, map<int, vector<int>> &g) {
  unordered_set<int> vi;
  queue<pair<int, int>> q;
  vi.insert(s);
  q.push(make_pair(s, 0));

  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    if (curr.second > 5)
      return true;
    for (int i = 0; i < g[curr.first].size(); i++) {
      int tmp = g[curr.first][i];
      if (!vi.count(tmp)) {
        q.push(make_pair(tmp, curr.second + 1));
        vi.insert(tmp);
      }
    }
  }

  return false;
}

int main() {
  fast;
  int t, n;
  string a, b;
  cin >> t;

  while (t--) {
    int u, v, nodes = 0, ans = 0, device = 0;
    bool ok = false;
    id = 0;
    cin >> n;
    map<string, int> m;
    map<int, vector<int>> g;

    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      u = get_id(m, a);
      v = get_id(m, b);
      g[u].push_back(v);
      g[v].push_back(u);
    }

    nodes = g.size();
    vector<vector<int>> paths;

    if (bfs(0, g)) cout << "NO" << endl;
    else cout << "YES" << endl;
  }

  return 0;
}
