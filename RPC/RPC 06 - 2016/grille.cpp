#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

using namespace std;

struct point {int x, y;
  point() {x = y = 0; }
  point(int _x, int _y) : x(_x), y(_y) {}
	void print() {
		cout << "X: " << x << " Y: " << y << endl;
	}
	bool operator < (const point &self) const {
		if (x == self.x) {
			return y < self.y;
		}
		return x < self.x;
	}
};

point rotate(point p, int n) {
	return point(p.y, -p.x);
}

void rotate_vector(vector<point> &p, int n) {
	for (int i = 0; i < p.size(); i++) {
		p[i] = rotate(p[i], n);
		p[i].y += (n - 1);
	}

	sort(p.begin(), p.end());
}

bool isValid(vector<vector<char> > &grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] < 'a' || grid[i][j] > 'z') return false;
    }
  }
  return true;
}

string display(vector<vector<char> > &grid, int n) {
  string x = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      x += grid[i][j];
    }
  }
  return x;
}

int main() {
  fast;
  int n;
  vector<point> holes;
  string x;

  cin >> n;
  vector<vector<char> > grid(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '.') {
        holes.push_back(point(i, j));
      }
    }
  }
  cin >> x;

  for (int i = 0; i < holes.size(); i++) {
    grid[holes[i].x][holes[i].y] = x[i];
  }

	rotate_vector(holes, n);

  for (int i = 0, k = holes.size(); i < holes.size(), k < holes.size() * 2;
  i++, k++) {
    grid[holes[i].x][holes[i].y] = x[k];
  }

  rotate_vector(holes, n);

  for (int i = 0, k = holes.size() * 2; i < holes.size(), k < holes.size() * 3;
  i++, k++) {
    grid[holes[i].x][holes[i].y] = x[k];
  }

  rotate_vector(holes, n);

  for (int i = 0, k = holes.size() * 3; i < holes.size(), k < holes.size() * 4;
  i++, k++) {
    grid[holes[i].x][holes[i].y] = x[k];
  }

  if (isValid(grid, n)) {
    cout << display(grid, n) << endl;
  }
  else cout << "invalid grille" << endl;

  return 0;
}
