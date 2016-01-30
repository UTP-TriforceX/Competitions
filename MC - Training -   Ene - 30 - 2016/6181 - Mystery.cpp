#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

int nextInt() {
  string buffer;
  getline(cin, buffer);
  return atoi(buffer.c_str());
}

int main() {
  string s, aux;
  int t, cases, n, m, x, pos;
  t = nextInt();

  for (int i = 0; i < t; i++) {
    int val = m = x = 0; aux = "";
    cases = nextInt();
    getline(cin, s);
    m = nextInt();
    getline(cin, aux);

    vector<int> index;
    cout << cases << " ";
    pos = 0;

    stringstream ss(aux);
    while (ss >> val) {
      index.push_back(val);
    }

    for (int j = 0; j < m; j++) {
      x = index[j];
      pos = pos + x;
      pos = (pos % s.size() + s.size()) % s.size();
      cout << s[pos];

      if (j == m - 1) cout << endl;
    }
  }
    return 0;
}
