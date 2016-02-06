#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

typedef long long ll;

int n, m, a, b;
char maps[504][504];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct state {
  int x, y;
  ll cost;
  bool type;
  state() {}
  state(int x, int y, bool t, ll cost) : x(x), y(y), type(t), cost(cost) {}
};

bool check(int x, int y) {
  return (x >= 0 and x < n and y >= 0 and y < m and maps[x][y] != '#');
}

ll bfs(int x, int y, bool type) {
  bool vi[504][504];
  memset(vi, false, sizeof(vi));
  queue<state> q;
  q.push(state(x, y, type, 0));
  vi[x][y] = true;

  while (!q.empty()) {
    state curr = q.front(); q.pop();
    if (curr.x == n - 1 and curr.y == m - 1) {
      return curr.cost;
    }

    for (int i = 0; i < 4; i++) {
      int nx = dx[i] + curr.x;
      int ny = dy[i] + curr.y;
      if (check(nx, ny) and !vi[nx][ny]) {
        vi[nx][ny] = true;
        ll cost = (!curr.type)? a : b;
        q.push(state(nx, ny, !curr.type, curr.cost + cost));
      }
    }
  }
  return -1;
}

int main() {
  fast;
  cin >> n >> m >> a >> b;
  swap(n, m);
  ll ans;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> maps[i][j];
    }
  }

  ans1 = bfs(0, 0, true);
  if (ans == -1) {
    cout << "IMPOSSIBLE" << endl;
  }
  else cout << ans << endl;

  return 0;
}
