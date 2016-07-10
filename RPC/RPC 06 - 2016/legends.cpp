#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

typedef long long ll;
#define MAX (ll)1e18

struct player {
	string s;
	ll k, d;
	player() {}
	player(string s, ll k, ll d) : s(s), k(k), d(d) {}
	bool operator < (const player &self) const {
		return (k * self.d) < (self.k * d);
	}
	bool operator == (const player &self) const {
		return (k * self.d) == (self.k * d);
	}
};


int main() {
	fast;
	int nc;
	cin >> nc;
	string s;
	ll k, d;

	while (nc--) {
		vector<string> ans;

		for (int i = 0; i < 5; i++) {
			cin >> s >> k >> d;
			if ((3 * k) < d) {
				ans.push_back(s);
			}
		}
		
		vector<player> p(5);
		player mini;
		bool flag = false;

		for (int i = 0; i < 5; i++) {
			cin >> p[i].s >> p[i].k >> p[i].d;
			if (p[i].d != 0) {
				flag = true;
			}
		}

		if (flag) {
			player mini("", 1000000099, 1);

			for (int i = 0; i < 5; i++) {
				if (p[i].d != 0 and p[i] < mini) {
					mini = p[i];
				}
			}

			for (int i = 0; i < 5; i++) {
				if ((p[i] == mini or p[i] < player("", 1, 3)) and p[i].d != 0) {
					ans.push_back(p[i].s);
				}
			}

			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " plz uninstall" << endl;
			}
		}

		else {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " plz uninstall" << endl;
			}
			for (int i = 0; i < p.size(); i++) {
				cout << p[i].s << " plz uninstall" << endl;
			}		
		}

	}

	return 0;
}