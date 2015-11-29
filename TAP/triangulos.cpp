#include <bits/stdc++.h>
using namespace std;

long long l, k;

bool find(long long m) {
  long long usados = 0, act = 0;
  for (long long i = 1; i <= 2 * l - 1; i += 2) {
    act += i;
    if (act >= m){
      usados++;
      act = 0;
    }
    if (usados >= k)
      return true;
  }
  return usados >= k;
}

int main() {
  cin >> l >> k;

  long long total = 1, area = l * l;

  while (total < area) {
    long long medio = (total + area + 1) / 2;
    if (find(medio))
      total = medio;
    else
      area = medio - 1;
  }
  cout << total << endl;
  return 0;
}
