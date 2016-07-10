#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
  fast;
  int n, m, row1, col1, row2, col2;
  char trash, p;
  char f[1001][1001], f2[1001][1001], ans[1001][1001];

  while (cin >> n >> m >> trash >> p >> trash and n+m) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> f[i][j];
        if (f[i][j] == p) {
          if (!flag) {
            row1 = i;
            col1 = j;
            flag = true;
          }
          ans[i][j] = ' ';
        }
        else {
          ans[i][j] = f[i][j];
        }
      }
    }

    flag = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> f2[i][j];
        if (f2[i][j] == p) {
          if (!flag) {
            row2 = i;
            col2 = j;
            flag = true;
          }
        } 
        else if (ans[i][j] == ' ') {
          ans[i][j] = f2[i][j];
        }
      }
    }

    int drow = row2 - row1;
    int dcol = col2 - col1;
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (f2[i][j] == p) {
          int nrow = i + drow;
          int ncol = j + dcol;
          if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m) {
            ans[nrow][ncol] = p;
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << ans[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
