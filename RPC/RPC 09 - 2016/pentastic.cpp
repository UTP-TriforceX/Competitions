#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'

using namespace std;

int findMin(vector<int> &penta) {
  int index = 0, mini = 10000;
  for (int i = 0; i < 5; i++) {
    if (penta[i] < mini) {
      mini = penta[i];
      index = i;
    }
  }
  return (mini < 0)? index : -1;
}

void solve(vector<int> &penta) {
  while (findMin(penta) != -1) {
    int index = findMin(penta);
    int negative = penta[index];
    penta[index] *= -1;
    if (index == 0) {
      penta[4] += negative;
      penta[1] += negative;
    } else if (index == 4) {
      penta[3] += negative;
      penta[0] += negative;
    } else {
      penta[index - 1] += negative;
      penta[index + 1] += negative;
    }
  }
}

int main() {
  fast;
  int t, tc = 1;
  cin >> t;

  while (t--) {
    vector<int> penta(5);
    for (int i = 0; i < 5; i++) {
      cin >> penta[i];
    }

    solve(penta);
    cout << "Pentagon #" << tc++ << ":" << endl;

    for (int i = 0; i < 5; i++) {
      if (i) cout << " ";
      cout << penta[i];
    }
    cout << endl;
  }

  return 0;
}
