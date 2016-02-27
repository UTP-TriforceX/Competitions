#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ff first
#define ss second
#define MP make_pair
#define PB push_back

using namespace std;

int n, m;
typedef pair<int,int> PII;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char coord[] = {'E', 'S', 'W', 'N'};
char table[66][66];

struct state{
  int x1, y1, x2, y2;
  char mov;

  state(){}
  state(int _x1, int _y1, int _x2, int _y2, char _mov) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), mov(_mov) {}
  bool operator < (const state &s) const {
    pair<PII, PII> a = MP(MP(x1, y1), MP(x2, y2));
    pair<PII, PII> b = MP(MP(s.x1, s.y1), MP(s.x2, s.y2));
    return a < b;
  }
};

string bfs(PII u, PII v) {
  map<state, state> prev;
  queue<state> q;

  q.push(state(u.ff, u.ss, v.ff, v.ss, '#'));
  prev[q.front()] = q.front();
  string ans = "";

  while (!q.empty()) {
    state curr = q.front(); q.pop();

    if(curr.x1 == curr.x2 and curr.y1 == curr.y2) {
      state cur = curr;

      while(cur.mov != '#'){
        ans.push_back(cur.mov);
        cur = prev[cur];
      }
      return ans;
    }

    for(int i = 0; i < 4; i++){
      int nx1 = (curr.x1 + dx[i] + m) % m;
      int nx2 = (curr.x2 + dx[i] + m) % m;
      int ny1 = (curr.y1 + dy[i] + n) % n;
      int ny2 = (curr.y2 + dy[i] + n) % n;
      state aux = state(nx1, ny1, nx2, ny2, coord[i]);

      if((prev.count(aux) == 0) and (table[nx1][ny1] == '.' or table[nx2][ny2] == '.')){
        if (table[nx1][ny1] != '.') {
          if (table[nx1][ny1] == 'G') continue;
          aux.x1 = curr.x1;
          aux.y1 = curr.y1;
        }

        if (table[nx2][ny2] != '.') {
          if (table[nx2][ny2] == 'G') continue;
          aux.x2 = curr.x2;
          aux.y2 = curr.y2;
        }

        if (prev.count(aux)) continue;
        q.push(aux);
        prev[aux] = curr;
      }
    }
  }
  return ans;
}

int main() {
  fast;
  int t;
  cin >> t;

  while (t--) {
    cin >> m >> n;
    vector<PII> index;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++){
        cin >> table[i][j];

        if (table[i][j] == 'P') {
          index.push_back(MP(i, j));
          table[i][j] = '.';
        }
      }
    }

    string ans = bfs(index[0], index[1]);
    reverse(ans.begin(), ans.end());
    (ans.size())? cout << ans.size() << " " << ans : cout << "IMPOSSIBLE";
    cout << endl;
  }

  return 0;
}
