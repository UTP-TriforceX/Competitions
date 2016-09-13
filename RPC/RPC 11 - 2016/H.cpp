#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

string vowels(string &s) {
  string ans = "";
  set<char> v = {'a', 'e', 'i', 'o', 'u'};

  for (int i = 0; i < s.size(); i++) {
    if (v.count(s[i])) {
      ans += s[i];
    }
  }

  return ans;
}

int main() {
  fast;
  string s;

  while (cin >> s) {
    string pal = vowels(s);
    string inv = string(pal.rbegin(), pal.rend());
    cout << ((pal == inv)? 'S' : 'N') << endl;
  }

  return 0;
}
