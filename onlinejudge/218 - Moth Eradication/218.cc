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
#define endl '\n'
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR ((a), 0, (b))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define R0F(a, b) ROF ((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define SET(a, b) memset((a), (b), sizeof(a))
template <class t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <class t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
  if (DEBUG) std::cerr
#define dvar(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
template <class a, class b>
ostream& operator<<(ostream& o, const pair<a, b>& p);
template <class T> struct IsC {
  template <class C> static char test(typename C::const_iterator*);
  template <class C> static int test(...);
  static const bool value = sizeof(test<T>(0)) == sizeof(char);
};
template <> struct IsC<string> { static const bool value = false; };
template <class C> typename enable_if<IsC<C>::value, ostream&>::type operator<<( ostream& o, const C& c) {
  o << '{';
  for (auto it = c.begin(); it != c.end();)
    o << *it << (++it != c.end() ? ", " : "}");
  return o;
}
template <class a, class b> ostream& operator<<(ostream& o, const pair<a, b>& p) {
  return o << '(' << p.fi << ", " << p.se << ')';
}

#define xx real()
#define yy imag()
using pt = complex<double>;
double dir(pt a, pt b, pt c) {
  pt ab = b - a, ac = c - a;
  return ab.xx * ac.yy - ab.yy * ac.xx;
}
bool cw(pt a, pt b, pt c) { return dir(a, b, c) < 0; }
bool ccw(pt a, pt b, pt c) { return dir(a, b, c) > 0; }
// careful with inputs for n < 2
vector<pt> convexHull(vector<pt>& pts) {
  int n = SZ(pts);
  if(n == 1) {
      vector<pt> res;
      res.pb(pts[0]);
      res.pb(pts[0]);
      return res;
  }
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

void solve(int n) {

    vector<pt> pts;
    F0R(i, n) {
        double x, y;
        cin >> x >> y;

        pts.eb(x, y);
    }
    
    vector<pt> res = convexHull(pts);

    double len = 0;
    F0R(i, SZ(res) - 1) {
        len += abs(res[i] - res[i + 1]);
        cout << setprecision(1) << fixed << res[i] << '-';
    }
    cout << res.back() << endl
         << "Perimeter length = " << setprecision(2) << len << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int tc = 0, n = 0; cin >> n, n; tc++) {
        if(tc) cout << endl;
        cout << "Region #" << tc + 1 << ":" << endl;
        solve(n);
    }
}
