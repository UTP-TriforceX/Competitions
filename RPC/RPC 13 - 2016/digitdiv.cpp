#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

const long long MOD = 1e9 + 7;

long long mod_pow(long long base, long long expo) {
  long long result = 1;
  while (expo) {
    if (expo & 1)
      result = (result * base) % MOD;
    base = (base * base) % MOD;
    expo >>= 1;
  }
  return result;
}

int main() {
  fast;
  long long n, m, ans;
  char digit;
  while (cin >> n >> m) {
    long long acum = 0, zeros = 0;
    for (int i = 0; i < n; i++) {
      cin >> digit;
      acum = (acum * 10 + ((digit - '0') % m)) % m;
      if (acum == 0) {
        zeros++;
      }
    }
    if (zeros == 0 or acum != 0)
      cout << 0 << endl;
    else
      cout << mod_pow(2, zeros - 1) << endl;
  }
  return 0;
}
