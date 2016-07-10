#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef unsigned long long int ll;


int main() {
  fast;
  string line;
  int q, i, k;
  while (cin >> line >> q) {
    while (q--) {
        cin >> i >> k;
        cout << line[(k + i - 2) % line.size()] << endl;
     }
  }
  return 0;
}
