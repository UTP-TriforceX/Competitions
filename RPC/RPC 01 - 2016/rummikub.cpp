#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back 

using namespace std;

int toInt(string x) {
	stringstream ss(x);
	int n;
	ss >> n;
	return n;
}

int main() {
	fast;
	int t, n;
	string s;
	cin >> t;

	while (t--) {
		cin >> n;
		bool ok = false, flag = false;
		unordered_map<char, vector<int> > frecL;
		unordered_map<int, unordered_set<char> > frecN;

		for (int i = 0; i < n; i++) {
			cin >> s;
			frecL[s[s.size() - 1]].pb(toInt(s.substr(0, s.size() - 1)));
			frecN[toInt(s.substr(0, s.size() - 1))].insert(s[s.size() - 1]);
		}

		for (auto &it : frecN) {
			if (it.second.size() >= 3) {
				ok = true;
				break;
			}
		}

		if (!ok) {
			for (auto &it : frecL) {
				sort(it.second.begin(), it.second.end());
				if (flag) break;

				if (it.second.size() >= 3) {
					for (int i = 0; i < it.second.size() - 2; i++) {
						if (it.second[i] + 1 == it.second[i + 1] and it.second[i] + 2 == it.second[i + 2]) {
							ok = true;
							flag = true;
							break;
						}
					}
				}
			}

			cout << ((ok)? "YES" : "NO") << endl;
		}

		else {
			cout << "YES" << endl;
		}

	}

	return 0;
}