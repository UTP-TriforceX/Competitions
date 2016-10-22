#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

void preprocess(string &text, vector<int> &starting, vector<int> &word_width) {
	int start = 0, width = 0;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ') {
			word_width[start] = width;
			width = 0;
			start = i+1;
			starting[i] = start;
		} else {
			starting[i] = start;
			width++;
		}
	}
	word_width[start] = width;
}

tuple<int, int> next_ints() {
	string line;
	int a, b;
	getline(cin, line);
	stringstream buffer(line);
	buffer >> a >> b;
	return make_tuple(a, b);
}

int main() {
	fast;
	string text;
	int a, b;
	while (getline(cin, text)) {
		tie(a, b) = next_ints();
		vector<int> starting(text.size()), word_width(text.size());
		preprocess(text, starting, word_width);
		for (int d = a; d <= b; d++) {
			int acum = 0, start = 0;
			while (true) {
				acum += word_width[start] + 1;
				if (start + d >= text.size()) {
					break;
				} else {
					start = starting[start + d];
				}
			}
			cout << acum - 1 << endl;
		}
	}
	return 0;
}
