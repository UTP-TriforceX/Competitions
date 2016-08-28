#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'

using namespace std;

bool match(string &t, string &p) {
  for (int i = 0; i < p.size(); i++) {
    if (t[i] != p[i] and p[i] != '-') {
      return false;
    }
  }
  return true;
}

int main() {
  fast;
  int words, m, count;
  string word, pattern;
  cin >> words;
  unordered_map<int, vector<string>> dic;
  vector<string> pat;
  while (words--) {
    cin >> word;
    dic[word.size()].push_back(word);
  }
  cin >> m;
  for (int i =1; i <= m; i++) {
    count = 0;
    cin >> pattern;
    cout << "Word #" << i << ": " << pattern << endl;
    for (auto &w: dic[pattern.size()]) {
      if (match(w, pattern)) {
        cout << w << endl;
        count++;
      }
    }
    cout << "Total number of candidate words = " << count << endl;
  }
  return 0;
}
