#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define D(x) cout << #x " = " << x << endl

using namespace std;

int main() {
	fast;
	int t, current, nativos, extranjeros;
	cin >> t;

	while (t--) {
		extranjeros = 0;
		cin >> nativos;

		while (cin >> current and current) {
			current -= extranjeros + nativos;

			if (current) {
				if (current >= nativos) {
					current -= nativos;
					nativos *= 2;
				} else {
					nativos += current;
					current = 0;
				}

				if (current >= extranjeros) {
					current -= extranjeros;
					nativos += extranjeros;
				} else {
					nativos += current;
					current = 0;
				}
			}

			extranjeros += current;
		}
		cout << extranjeros << endl;
	}

	return 0;
}
