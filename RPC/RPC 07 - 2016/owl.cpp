#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int toInt(string &s) {
	return atoi(s.c_str());
}

int main() {
	fast;
	string n;

	while (cin >> n and n != "END") {
		for (int i = n.size() - 1; i >= 0; i--) {
			if (n[i] == '0') continue;
			else {
				n[i] = n[i] - 1;
				break;
			}
		}
		cout << toInt(n) << endl;
	}

	return 0;
}
