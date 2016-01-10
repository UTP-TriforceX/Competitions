#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator * (double c) const { return PT(x * c, y * c); }
  PT operator / (double c) const { return PT(x / c, y / c); }
};

double dot(PT p, PT q) {
  return p.x * q.x + p.y * q.y;
}

double dist2 (PT p, PT q) {
  return dot(p - q, p - q);
}

PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}

bool PointInPolygon(const vector<PT> &p, PT q) {
  bool c = false;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y and q.y < p[j].y or p[j].y <= q.y and q.y < p[i].y) and
         q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}

bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
      return true;
  return false;
}

int main() {
  fast;
  double xp, yp, x, y;
  int t, n, p;
  cin >> t;

  while (t--) {
    cin >> p >> xp >> yp;
    PT q(xp, yp);
    string ans = "";
    while (p--) {
      cin >> n;
      vector<PT> polygon(n);
      for (int i = 0; i < n; i++) {
        cin >> x >> y;
        polygon[i] = PT(x, y);
      }

      if (PointOnPolygon(polygon, q)) ans += "0 ";
      else if (PointInPolygon(polygon, q)) ans += "1 ";
      else ans += "2 ";
    }
    ans = ans.substr(0, ans.size() - 1);
    cout << ans << endl;
  }
  return 0;
}
