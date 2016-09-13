#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
  fast;
  int n;

  while (cin >> n) {
    int maxAns = -1;
    vector<int> tr(n), left, right;
    for (int i = 0; i < n; i++) cin >> tr[i];

    if (n > 2) {
      int aux = 1;
      for (int i = 0; i < n; i++) {
        if(tr[i] >= aux){
          left.push_back(aux);
          aux += 1;
        }
        else{
          left.push_back(tr[i]);
          aux = tr[i] + 1;
        }
      }

      aux = 1;
      for (int i = n - 1; i >= 0; i--) {
        if(tr[i] >= aux){
          right.push_back(aux);
          aux += 1;
        }
        else{
          right.push_back(tr[i]);
          aux = tr[i] + 1;
        }
      }

      reverse(right.begin(), right.end());

      int Maxv = -1;
      for (int i = 0; i <= n; i++) {
        Maxv = max(Maxv, min(left[i], right[i]));
      }

      cout << Maxv << endl;

    } else {
      cout << 1 << endl;
    }

  }

  return 0;
}
