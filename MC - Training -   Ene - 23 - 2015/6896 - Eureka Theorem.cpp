#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define npos string::npos
#define MP make_pair
#define ff first
#define ss second
#define oo INT_MAX

using namespace std;

vector<int> gauss(1002);
set<int> verify;

void calc() {
  for (int i = 1; i < gauss.size(); i++) gauss[i] = i;
  for (int i = 1; i < gauss.size(); i++) {
    gauss[i] += gauss[i - 1];
    verify.insert(gauss[i]);
  }
}

int main() {
  fast;
  bool ans = false, flag = false;
  int t, k;
  calc();
  cin >> t;

  while (t--) {
    ans = flag = false;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      if (flag) break;
      for (int j = 1; j <= k; j++) {
        if (verify.count(k - (gauss[i] + gauss[j]))) {
          ans = true;
          flag = true;
          break;
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
