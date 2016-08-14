#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'

using namespace std;

int main() {
	fast;
	int n;
	cin >> n;

	while (n--) {
		vector<int> us(3), ru(3);
		bool medal_win = false, color_win = false;
		int count_us = 0, count_ru = 0;

		for (int i = 0; i < 3; i++) {
			cin >> us[i];
			count_us += us[i];
			cout << us[i] << " ";
		}

		for (int i = 0; i < 3; i++) {
			cin >> ru[i];
			count_ru += ru[i];
			cout << ((i)? " ": "") << ru[i];
		}

		cout << endl;
		medal_win = (count_us > count_ru);

		for (int i = 0; i < 3; i++) {
			if (us[i] > ru[i]) {
				color_win = true;
				break;
			} else if (us[i] < ru[i]) {
				break;
			}
		}

		if (medal_win and color_win) {
			cout << "both";
		} else if (medal_win) {
			cout << "count";
		} else if (color_win) {
			cout << "color";
		} else {
			cout << "none";
		}
		cout << endl;
	}
	return 0;
}
