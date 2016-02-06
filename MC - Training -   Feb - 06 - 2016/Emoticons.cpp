#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

int main() {
  fast;
  int n, hap = 0, sad = 0;
  cin >> n;

  vector<char> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];

  for (int i = 0; i < n; i++) {
    if (vec[i] == ':') {
      if (vec[i - 1] == '(' and (i - 1) >= 0)      hap++;
      else if (vec[i - 1] == ')' and (i - 1) >= 0) sad++;
      if (vec[i + 1] == '(' and (i + 1) < n)       sad++;
      else if (vec[i + 1] == ')' and (i + 1) < n)  hap++;
    }
  }

  cout << ((hap == sad)? "BORED" : (hap > sad)? "HAPPY" : "SAD") << endl;
  return 0;
}
