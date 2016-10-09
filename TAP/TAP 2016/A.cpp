#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define npos string::npos

using namespace std;

int main() {
  fast;
  string s;

  while (cin >> s) {
    cout << ((s.find('i') != npos)? 'N' : 'S') << endl;
  }

  return 0;
}
