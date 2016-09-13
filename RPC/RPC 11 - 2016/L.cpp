#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

int h, l;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool check(int x, int y) {
  return x >= 0 and x < h and y >= 0 and y < l;
}

void floodFill(int x, int y, vector<vector<int>> &board, map<int, vector<int>> &adj, vector<vector<bool>> &visit) {
  queue<pair<int, int>> q;
  int cont = 1;
  visit[x][y] = true;
  int element = board[x][y];
  q.push(make_pair(x, y));

  while (!q.empty()) {
    pair<int, int> curr = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = dx[i] + curr.first;
      int ny = dy[i] + curr.second;
      if (check(nx, ny) and !visit[nx][ny] and board[nx][ny] == element) {
        visit[nx][ny] = true;
        cont++;
        q.push(make_pair(nx, ny));
      }
    }
  }

  adj[element].push_back(cont);
}

int main() {
  fast;

  while (cin >> h >> l) {
    map<int, vector<int>> adj;
    vector<vector<int>> board(h, vector<int>(l));
    vector<vector<bool>> visit(h, vector<bool>(l, false));

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < l; j++) {
        cin >> board[i][j];
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < l; j++) {
        if (!visit[i][j]) {
          floodFill(i, j, board, adj, visit);
        }
      }
    }

    int minSize = 9999999;
    for (const auto &it : adj) {
      for (int i = 0; i < it.second.size(); i++) {
        minSize = min(minSize, it.second[i]);
      }
    }

    cout << minSize << endl;

  }

  return 0;
}
