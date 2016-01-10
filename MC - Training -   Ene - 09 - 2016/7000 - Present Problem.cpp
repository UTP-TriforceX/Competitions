#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define MP make_pair
#define ff first
#define ss second

using namespace std;

typedef pair <int, int> PII;
typedef vector <priority_queue <PII, vector <PII>, greater <PII> > > Graph;
int nodes, edges;

int solve(int source, Graph g) {
  PII ans(0, source);
  PII curr;

  while (!g[ans.ss].empty()) {
    curr = g[ans.ss].top();
    g[ans.ss].pop();

    while (curr.ff <= ans.ff) {
      if (g[ans.ss].size() == 1) {
        PII tmp = g[ans.ss].top(); g[ans.ss].pop();
        if (tmp.ff > ans.ff) curr = tmp;
        else curr = ans;
        break;
      }
      curr = g[ans.ss].top(); g[ans.ss].pop();
    }

    if (curr.ff > ans.ff) ans = curr;
    if (g[ans.ss].size() == 1) {
      curr = g[ans.ss].top(); g[ans.ss].pop();
      if (curr.ff > ans.ff) ans = curr;
      break;
    }
  }
  return ans.ss;
}

int main() {
  fast;
  int t, l, x, k;
  cin >> t;

  while (t--) {
    cin >> nodes >> edges >> l;
    Graph g(nodes);

    while (edges--) {
      cin >> x >> k;
      g[x].push(MP(k, x +1));
      g[x + 1].push(MP(k, x));
    }

    for (int i = 0; i < nodes; i++)
      cout << solve(i, g) << endl;
  }
  return 0;
}
