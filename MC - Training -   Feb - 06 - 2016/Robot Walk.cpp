#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

int main() {
  fast;
  char pos;
  int n, x, m;
  string s, mov, ans = "";
  cin >> n >> x >> s >> m >> mov;
  ans += s[x - 1];

  for (int i = 0; i < mov.size(); i++) {
    if (mov[i] == 'R') x++;
    else               x--;
    ans += s[x - 1];
  }
  
  cout << ans << endl;
  return 0;
}
