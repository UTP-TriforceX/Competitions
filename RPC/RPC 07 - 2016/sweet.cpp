#include <bits/stdc++.h>

using namespace std;

int main() {
	long long cant = 0, in;
	int i = 1;

	while (cin >> in and in) {
		cant += in;
		if (cant >= 50) {
			if ((cant / 50) > 1) {
				cout << "Input #" << i << ": Totally Sweet!" << endl;
			} 
			else {
				cout << "Input #" << i << ": Sweet!" << endl;
			}
			cant = cant % 50;
		}
		i++;
	}
	return 0;
}
