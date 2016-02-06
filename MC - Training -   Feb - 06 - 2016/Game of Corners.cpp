#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
  fast;
  ll n, m;
  cin >> n >> m;
  if (n < m) swap(n, m);
  cout << ((n + 1) * m) << endl;
  return 0;
}
