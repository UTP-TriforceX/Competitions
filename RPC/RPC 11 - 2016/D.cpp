#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

vector<int> divisors(int n) {
  vector<int> ans;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i != 1) ans.push_back(i);
      if (i * i < n) ans.push_back(n / i);
    }
  }
  return ans;
}

int main() {
  fast;
  int a, b, c, d;

  while (cin >> a >> b >> c >> d) {
    int mini = 1e9 + 5;
    vector<int> vec = divisors(c);
    for (auto &it : vec) {
      if ((it % a == 0) and (it % b != 0) and (d % it != 0)) {
        mini = min(mini, it);
      }
    }
    cout << ((mini == 1e9 + 5)? -1 : mini) << endl;
  }

  return 0;
}
