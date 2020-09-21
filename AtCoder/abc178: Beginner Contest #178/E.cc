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
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define SZ(x) (int)(x).size()
#define endl '\n'
#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR (a, 0, (b))
#define CEIL(a, b) ((a) + (b)-1) / (b)
template <class T>
bool ckmin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
  if (DEBUG) std::cerr
#define dvar(...) " [" << #__VA_ARGS__ ": " << mt(__VA_ARGS__) << "] "
template <typename T>
struct IsC {
  template <typename C>
  static char test(typename C::const_iterator*);
  template <typename C>
  static int test(...);
  static const bool value = sizeof(test<T>(0)) == sizeof(char);
};
template <>
struct IsC<string> {
  static const bool value = false;
};
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream&, const C&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);
template <typename... T> using TS = tuple_size<tuple<T...>>;
template<size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return o << ", " << get<idx>(t) << ')';
}
template<size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << ", " << get<idx>(t), t);
}
template<size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << '(' << get<idx>(t), t);
}
template<typename T>
ostream& operator<<(ostream& o, const tuple<T>& t) {
  return o << get<0>(t);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
  return o << mt(p.fi, p.se);
}
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(
    ostream& o, const C& c) {
  o << '[';
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    o << *it << (next(it) != c.cend() ? ", " : "");
  return o << ']';
}
template <typename T>
void tprint(vector<vector<T>>& v, size_t width = 0, ostream& o = cerr) {
  if (!DEBUG) return;
  for (const auto& vv : v) {
    for (const auto& i : vv) o << setw(width) << i;
    o << endl;
  }
}

#define xx real()
#define yy imag()
const double EPS = 1e-9;
const double INF = numeric_limits<double>::max();
using pt = complex<double>;
struct Line {
  double a, b, c;
};  // ax + by + c = 0
double dot(pt a, pt b) { return a.xx * b.xx + a.yy * b.yy; }
double cross(pt a, pt b) { return a.xx * b.yy - a.yy * b.xx; }
double dir(pt a, pt b, pt c) { return cross(b - a, c - a); }
bool cw(pt a, pt b, pt c) { return dir(a, b, c) < 0; }
bool ccw(pt a, pt b, pt c) { return dir(a, b, c) > 0; }
bool collinear(pt a, pt b, pt c) { return abs(dir(a, b, c)) < EPS; }
// Angle between a and b with o as origin (ccw).
// Return value in [0, 2PI)
double angle(pt a, pt b) {
  double ang = arg(a) - arg(b);
  return ang < 0 ? ang + 2 * M_PI : ang;
}
double angle(pt a, pt b, pt o) { return angle(b - o, a - o); }
// Theta in radiens
pt rotate(pt a, double theta) { return a * polar(1.0, theta); }
Line ptToLine(pt p1, pt p2) {
  if (abs(real(p1) - real(p2)) < EPS) {
    return {1.0, 0.0, -real(p1)};
  } else {
    double a = -(imag(p1) - imag(p2)) / (real(p1) - real(p2)),
           c = -(a * real(p1)) - imag(p2);
    return {a, 1.0, c};
  }
}
bool areParallel(Line l1, Line l2) {
  return abs(l1.a - l2.a) < EPS && abs(l1.b - l2.b) < EPS;
}
bool areSame(Line l1, Line l2) {
  return areParallel(l1, l2) && abs(l1.c - l2.c) < EPS;
}
pt intersectPt(Line l1, Line l2) {
  // Does not handle if same or parrallel
  if (areParallel(l1, l2)) return pt(-INF, -INF);
  double x =
      (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  double y;
  if (abs(l1.b) < EPS)
    y = -(l1.a * x + l1.c);
  else
    y = -(l2.a * x + l2.c);
  return pt(x, y);
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

// careful with inputs for n < 2
vector<pt> convexHull(vector<pt>& pts) {
  int n = SZ(pts);
  sort(ALL(pts),
       [](pt a, pt b) { return mp(a.xx, a.yy) < mp(b.xx, b.yy); });
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

ll dist(pt a, pt b) {
    return abs(a.xx - b.xx) + abs(a.yy - b.yy);
}

ll findForInd(int i, vector<pt>& hull) {
    int l = 0;
    int r = SZ(hull) - 2;
    while(l < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        pt elem1 = hull[(i + 1 + m1) % SZ(hull)];
        pt elem2 = hull[(i + 1 + m2) % SZ(hull)];
        if(dist(hull[i], elem1) < dist(hull[i], elem2)) {
            l = m1 + 1;
        } else {
            r = m2 - 1;
        }
    }
    return dist(hull[i], hull[(i + 1 + l) % SZ(hull)]);
}

void solve() {
    int n;
    cin >> n;

    set<ii> seen;
    vector<pt> pts;
    F0R(i, n) {
        int x, y;
        cin >> x >> y;
        if(!seen.count(mp(x, y))) {
            seen.emplace(x, y);
            pts.eb(x, y);
        }
    }

    if(SZ(pts) < 2) {
        cout << 0 << endl;
        return;
    }

    vector<pt> hull = convexHull(pts);
    hull.pop_back();
    ll res = 0;
    F0R(i, SZ(hull))
        ckmax(res, findForInd(i, hull));
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc = 1;
    FOR(i, 1, tc + 1) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}
