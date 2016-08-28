#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define N 103

using namespace std;

typedef vector<vector<int>> Graph;
int memo[N][N], n, m;

int dp(int i, int j, Graph &board) {
  if (i == n-1 and j == m-1) return 0;
  if (i >= n) return 0;
  if (j >= m) return 0;
  if (memo[i][j] != -1) return memo[i][j];

  int ans = max(dp(i+1, j, board) + board[i][j], dp(i, j+1, board) + board[i][j]);
  return memo[i][j] = ans;
}

int main(int argc, char const *argv[]) {
  fast;
  int tc = 1, t;
  cin >> t;

  while (t--) {
    cin >> n >> m;
    Graph board(n, vector<int>(m));
    char c;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i == 0 and j == 0) or (i == n - 1 and j == m - 1)) {
          cin >> c;
          board[i][j] = 0;
        } else {
          cin >> board[i][j];
        }
      }
    }
    memset(memo, -1, sizeof(memo));
    cout << "Game Board #" << tc++ << ": ";
    cout << dp(0, 0, board) << endl;
  }
  return 0;
}
