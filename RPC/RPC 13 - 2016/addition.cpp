#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

string num(string x) {
  if (x == "xxxxxx...xx...xx...xx...xx...xxxxxx") return "0";
  else if (x == "....x....x....x....x....x....x....x") return "1";
  else if (x == "xxxxx....x....xxxxxxx....x....xxxxx") return "2";
  else if (x == "xxxxx....x....xxxxxx....x....xxxxxx") return "3";
  else if (x == "x...xx...xx...xxxxxx....x....x....x") return "4";
  else if (x == "xxxxxx....x....xxxxx....x....xxxxxx") return "5";
  else if (x == "xxxxxx....x....xxxxxx...xx...xxxxxx") return "6";
  else if (x == "xxxxx....x....x....x....x....x....x") return "7";
  else if (x == "xxxxxx...xx...xxxxxxx...xx...xxxxxx") return "8";
  else if (x == "xxxxxx...xx...xxxxxx....x....xxxxxx") return "9";
  else return "+";
}

string ascii(char x) {
  if (x == '0')      return "xxxxxx...xx...xx...xx...xx...xxxxxx";
  else if (x == '1') return "....x....x....x....x....x....x....x";
  else if (x == '2') return "xxxxx....x....xxxxxxx....x....xxxxx";
  else if (x == '3') return "xxxxx....x....xxxxxx....x....xxxxxx";
  else if (x == '4') return "x...xx...xx...xxxxxx....x....x....x";
  else if (x == '5') return "xxxxxx....x....xxxxx....x....xxxxxx";
  else if (x == '6') return "xxxxxx....x....xxxxxx...xx...xxxxxx";
  else if (x == '7') return "xxxxx....x....x....x....x....x....x";
  else if (x == '8') return "xxxxxx...xx...xxxxxxx...xx...xxxxxx";
  else if (x == '9') return "xxxxxx...xx...xxxxxx....x....xxxxxx";
}

int main() {
  fast;
  vector<string> v(7);

  while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5] >> v[6]) {
    string n;
    for (int i = 0; i < v[0].size(); i += 6) {
      string tmp;
      for (int j = 0; j < 7; j++) {
         tmp += v[j].substr(i, 5);
      }
      n += num(tmp);
    }

    int index = n.find("+");
    string a = n.substr(0, index);
    string b = n.substr(index + 1);
    int result = atoi(a.c_str()) + atoi(b.c_str());
    string c = to_string(result);

    vector<string> ans(7);
    for (int i = 0; i < c.size(); i++) {
      string asc = ascii(c[i]);
      for (int j = 0, k = 0; j < 7; j++, k += 5) {
          ans[j] += asc.substr(k, 5);
          ans[j] += ".";
      }
    }

    for (int i = 0; i < 7; i++) {
      cout << ans[i].substr(0, ans[i].size() - 1) << endl;
    }
  }

  return 0;
}
