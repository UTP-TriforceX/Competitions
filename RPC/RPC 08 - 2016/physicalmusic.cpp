#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'

using namespace std;

int main() {
	fast;
	int t, n;
	cin >> t;
	while (t--) {
		int maxi = 0, single;
		cin >> n;

		vector<int> chart(n), ans;
		for (int i = 0; i < n; i++) {
			cin >> single;
			chart[single - 1] = i;
		}

		for (int i = 0; i < n; i++) {
			maxi = max(chart[i], maxi);
			if (chart[i] < maxi) ans.push_back(i + 1);
		}

		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}

	return 0;
}
