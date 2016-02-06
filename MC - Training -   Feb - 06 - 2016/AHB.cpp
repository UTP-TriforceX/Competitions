#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

string to_str(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}

int to_int(string s) {
  stringstream ss(s);
  int value;
  ss >> value;;
  return value;
}

int main() {
  fast;
  string a, b, ans = "";
  cin >> a >> b;

  for (int i = 0; i < a.size(); i++) {
    ans += to_str(abs((a[i]-'0') - (b[i]-'0')));

  }
  cout << to_int(ans) << endl;
  return 0;
}
