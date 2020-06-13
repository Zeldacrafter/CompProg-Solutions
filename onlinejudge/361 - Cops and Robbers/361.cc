#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SZ(x) (int)(x).size()
//#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define SET(a, b) memset((a), (b), sizeof(a))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

#define xx real()
#define yy imag()
const double EPS = 1e-9;
using pt = complex<double>;

double dot(pt a, pt b) { return a.xx * b.xx + a.yy * b.yy; }
double cross(pt a, pt b) { return a.xx * b.yy - a.yy * b.xx; }
double dir(pt a, pt b, pt c) { return cross(b - a, c - a); }
bool cw(pt a, pt b, pt c) { return dir(a, b, c) < 0; }
bool ccw(pt a, pt b, pt c) { return dir(a, b, c) > 0; }
bool collinear(pt a, pt b, pt c) { return abs(dir(a, b, c)) < EPS; }

// careful with inputs for n < 2
vector<pt> convexHull(vector<pt>& pts) {
  int n = SZ(pts);
  sort(ALL(pts), [](pt a, pt b) { return mp(a.xx, a.yy) < mp(b.xx, b.yy); });
  vector<pt> up, down;
  up.eb(pts[0]); down.eb(pts[0]);
  FOR (i, 1, n) {
    if (i == n - 1 || ccw(pts[0], pts[n - 1], pts[i])) {
      while (SZ(up) > 1 &&
             ccw(up[SZ(up) - 2], up[SZ(up) - 1], pts[i]))
        up.pop_back();
      up.eb(pts[i]);
    }
    if (i == n - 1 || cw(pts[0], pts[n - 1], pts[i])) {
      while (SZ(down) > 1 &&
             cw(down[SZ(down) - 2], down[SZ(down) - 1], pts[i]))
        down.pop_back();
      down.eb(pts[i]);
    }
  }
  vector<pt> ans(up);
  ans.insert(ans.end(), 1 + RALL(down));
  return ans;
}

bool inTriangle(pt a, pt b, pt c, pt p) {
  return abs(-abs(dir(a, b, c)) + abs(dir(a, b, p)) + abs(dir(a, p, c)) + abs(dir(p, b, c))) < EPS;
}
bool inPolygon(vector<pt>& poly, pt p) {
  int l = 1, r = SZ(poly) - 2;
  while (l < r) {
    int mid = (l + r) / 2;
    if (cw(poly[0], poly[mid], p)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return inTriangle(poly[0], poly[l], poly[l - 1], p);
}

double distToLine(pt p, pt a, pt b, bool segment = false) {
  pt ap = p - a, ab = b - a;
  double u = dot(ap, ab) / (abs(ab) * abs(ab));
  if (segment) {
    if (u < 0.0) return abs(p - a);  // a is closest
    if (u > 1.0) return abs(p - b);  // b is closest
  }
  return abs(p - a - ab * u);      // closest is in segment.
}

bool isOk(vector<pt>& pts, pt p, bool col) {
    if(!SZ(pts)) return false;
    if(SZ(pts) == 1) return abs(pts[0] - p) < EPS;
    if(col)
        return SZ(pts) > 2 && distToLine(p, pts[0], pts.back(), true) < EPS;
    return inPolygon(pts, p);
}

void solve(int c, int r, int o) {

    vector<pt> cops, robbers;
	F0R(_, c) {
		int x, y;
		cin >> x >> y;
		cops.eb(x, y);
	}
	F0R(_, r) {
		int x, y;
		cin >> x >> y;
		robbers.eb(x, y);
	}

    sort(ALL(cops), [](pt a, pt b) { return mp(a.xx, a.yy) < mp(b.xx, b.yy); });
    sort(ALL(robbers), [](pt a, pt b) { return mp(a.xx, a.yy) < mp(b.xx, b.yy); });
    cops.resize(distance(cops.begin(), unique(ALL(cops))));
    robbers.resize(distance(robbers.begin(), unique(ALL(robbers))));

    bool colC = true;
    F0R(i, SZ(cops) - 2)
        if(!collinear(cops[i], cops[i + 1], cops[i + 2])) {
            colC = false;
            break;
        }
    bool colR = true;
    F0R(i, SZ(robbers) - 2)
        if(!collinear(robbers[i], robbers[i + 1], robbers[i + 2])) {
            colR = false;
            break;
        }

    if(SZ(cops) > 2 && !colC)
        cops = convexHull(cops);
    if(SZ(robbers) > 2 && !colR)
        robbers = convexHull(robbers);

	F0R(_, o) {
        int x, y;
        cin >> x >> y;
        pt cit(x, y);
		
        cout << "     Citizen at " << cit << " is ";
		if(isOk(cops, cit, colC)) cout << "safe.\n";
		else if(isOk(robbers, cit, colR)) cout << "robbed.\n";
		else cout << "neither.\n";
	}

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i = 1;;++i) {
        int c, r, o;
        cin >> c >> r >> o;
        if(!c && !r && !o) break;
		cout << "Data set " << i << ":\n";
        solve(c, r, o);
        cout << endl;
	}
}
