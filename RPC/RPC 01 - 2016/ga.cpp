#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define pb push_back
#define MP make_pair

using namespace std;
typedef long long ll;

struct state {
	int x, y;
	state() {}
	state(int x, int y) : x(x), y(y) {}
};

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int n;
char grid[103][103];
bool vi[103][103];

bool check (int x, int y) {
	return x >= 0 and x < n and y >= 0 and y < n;
}

ll bfs(int x, int y) {
	ll ans = 0;
	vi[x][y] = true;
	queue<state> q;
	q.push(state(x, y));

	while (!q.empty()) {
		state curr = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = dx[i] + curr.x;
			int ny = dy[i] + curr.y;

			if (check(nx, ny) and !vi[nx][ny] and grid[nx][ny] == '-') {
				vi[nx][ny] = true;
				q.push(state(nx, ny));
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	fast;
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		ll ans = 0;
		memset(vi, false, sizeof(vi));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 'w' and !vi[i][j]) {
					ans = max(ans, bfs(i, j));
				}
			}
		}

		cout << ans << endl;

	}

	return 0;
}
