#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define EPS 10e-7

using namespace std;

typedef long double ld;

int main() {
  fast;
  vector<ld> Log(2501);
  for(int i = 1; i <= 2500; i++) {
    Log[i] = Log[i - 1] + log(i);
  }

  int t, a, b, c, aux;
  ld _a, _b, _c;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    cin >> a >> b >> c;
    _a = 0.0; _b = 0.0; _c = 0.0;
    for (int j = 0; j < a; j++) {
      cin >> aux;
      _a += Log[aux];
    }
    for (int j = 0; j < b; j++) {
      cin >> aux;
      _b += Log[aux];
    }
    for (int j = 0; j < c; j++) {
      cin >> aux;
      _c += Log[aux];
    }

    cout << "Case #" << i << ": ";
    if (((_a - _b) > EPS) and ((_a - _c) > EPS)) cout << "A" << endl;
    else if (((_b - _a) > EPS) and ((_b - _c) > EPS)) cout << "B" << endl;
    else if (((_c - _a) > EPS) and ((_c - _b) > EPS)) cout << "C" << endl;
    else cout << "TIE" << endl;
  }


  return 0;
}
