#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
  fast;
  int a, b, c;
  while (cin >> a >> b >> c) {
    if ((a == b + c) or (b == a + c) or (c == a + b) or (a == b) or (a == c) or (b == c)) {
      cout << "S" << endl;
    } else cout << "N" << endl;
  }
  return 0;
}
