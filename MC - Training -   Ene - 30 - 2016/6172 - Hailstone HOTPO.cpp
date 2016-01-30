#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

int max_collatz(int n) {
  int maxi = n;
  while (n != 1) {
    if (n % 2 == 0) {
      n = (n >> 1);
    }
    else {
      n = (n * 3) + 1;
    }
    maxi = max(maxi, n);
  }
  return maxi;
}

int main() {
  fast;
  int p, set, n;
  cin >> p;

  while (p--) {
    cin >> set >> n;
    int ans = max_collatz(n);
    cout << set << " " << ((ans != -1)? ans : 1) << endl;
  }

  return 0;
}
