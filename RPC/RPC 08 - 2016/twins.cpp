#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'

using namespace std;

int main() {
	fast;
	int n, num;
	cin >> n;

	while (n--) {
		bool z = false, m = false;

		for (int i = 0; i < 10; i++) {
			cin >> num;
			if (num == 18) m = true;
			if (num == 17) z = true;
			cout << ((i)? " ": "") << num;
		}

		cout << endl;
		if (z and m) cout << "both";
		else if (z)  cout << "zack";
		else if (m)  cout << "mack";
		else    		 cout << "none";
		cout << endl;
	}

	return 0;
}
