#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MP make_pair

// TLE

using namespace std;

typedef long long ll;

struct terna {
    ll b, h, l;
    terna() {}
    terna(ll b, ll h, ll l) : b(b), h(h), l(l) {}
};

ll solve(vector<terna> &path, terna start) {
    ll sum = 0, maxH = -1;
    while (path[start.b].b != -1) {
        sum += start.l;
        maxH = max(maxH, start.h);
        start = path[start.b];
    }
    return sum * maxH;
}

ll bfs(int source, int target, vector<vector<terna> > &G) {
    vector<bool> vi(G.size(), false);
    vector<terna> path(G.size());
    queue<terna> q;
    vi[source] = true;
    q.push(terna(source, 0, 0));
    path[source] = terna(-1, -1, -1);

    while (!q.empty()) {
        terna curr = q.front();
        q.pop();

        if (curr.b == target) {
            return solve(path, curr);
        }

        for (int i = 0; i < G[curr.b].size(); i++) {
            terna tmp = G[curr.b][i];
            if (!vi[tmp.b]) {
                vi[tmp.b] = true;
                path[tmp.b] = curr;
                q.push(tmp);
            }
        }
    }
}

int main() {
  fast;
  ll a;
  int n, p, s, t;
  terna tr;
  cin >> n;
  vector<vector<terna> > G(n);

  for (int i = 0; i < n - 1; i++) {
    cin >> a >> tr.b >> tr.h >> tr.l;
    tr.b--;
    a--;

    G[a].push_back(tr);
    swap(a, tr.b);
    G[a].push_back(tr);
  }

  cin >> p;
  map<pair<int, int>, ll> memo;
  while (p--) {
    cin >> s >> t;
    if (memo.count(MP(s - 1, t - 1)))
        cout << memo[MP(s - 1, t - 1)] << endl;
    else {
        ll ans = bfs(s - 1, t - 1, G);
        memo[MP(s - 1, t - 1)] = ans;
        cout << ans << endl;
    }
  }

  return 0;
}
