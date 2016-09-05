#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define N 100000 + 5

using namespace std;

vector<int> phi_sieve(N);

// int phi(int n) {
//   int ans = n;
//
//   for (int i = 2; i * i < n; i++) {
//     if (n % i == 0) ans -= ans / i;
//     while (n % i == 0) n /= i;
//   }
//
//   if (n > 1) ans -= ans / n;
//   return ans;
// }

bool isPrime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void sieve() {
  for (int i = 1; i < N; i++)
    phi_sieve[i] = i;

  for (int i = 1; i < N; i++) {
    if (isPrime(i)) {
      for (int j = i; j < N; j += i) {
        phi_sieve[j] -= phi_sieve[j] / i;
      }
    }
  }
}

int main() {
  fast;
  int t, n;
  sieve();
  cin >> t;

  while (t--) {
    cin >> n;
    cout << phi_sieve[n] << endl;
  }

  return 0;
}
