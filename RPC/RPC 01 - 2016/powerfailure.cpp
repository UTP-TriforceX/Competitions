#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

const int SZ = 1000010;

int p[SZ];
bool power[SZ];

int find_set(int x) {
  return (x == p[x])? x : p[x] = find_set(p[x]);
}

void union_set(int x, int y) {
  int px = find_set(x);
  int py = find_set(y);
  if (power[px] or power[py]) power[px] = power[py] = true;
  p[px] = py;
}

void init() {
  for (int i = 0; i < SZ; i++) {
    p[i] = i;
    power[i] = false;
  }
}

int main() {
  fast;
  int t;
  cin >> t;

  while (t--) {
    unordered_set<int> ans;
    int n, m, p, c, u, v;
    char d;
    cin >> n >> m >> p >> c;
    init();

    for (int i = 0; i < p; i++) {
      cin >> u >> v;
      u++; v++;
      int aux = u * 110 + v;
      power[aux] = true;
    }

    for (int i = 0; i < c; i++) {
      cin >> u >> v >> d;
      u++; v++;
      int p1 = u * 110 + v;
      int p2 = 0;

      if (d == 'R') p2 = (u + 1) * 110 + v;
      else          p2 = u * 110 + (v + 1);

      if (find_set(p1) != find_set(p2)) {
        union_set(p1, p2);
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int index = i * 110 + j;
        if (!power[find_set(index)])
          ans.insert(find_set(index));
      }
    }

    cout << ans.size() << endl;
  }

  return 0;
}
