#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

vector<int> triangulars(50000000 + 5, -1);

bool isTriangular(int n) {
  int tr = (-1 + sqrt(1.0 + 8.0 * n)) / 2.0;
  tr = (tr * (tr + 1)) >> 1;
  return tr == n;
}

void calc() {
  int j = 0;
  for (int i = 0; i < triangulars.size(); i++) {
    if (isTriangular(i)) {
      triangulars[i] = j++;
    }
  }
}

int main() {
  fast;
  int t, n;
  cin >> t;
  calc();

  while (t--) {
    cin >> n;
    if (triangulars[n] != -1) {
      cout << triangulars[n] - 1 << endl;
    } else {
      cout << "No solution" << endl;
    }
  }

  return 0;
}
