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
using pt = complex<int>;

double cross(pt a, pt b) { return a.xx * b.yy - a.yy * b.xx; }
double dir(pt a, pt b, pt c) { return cross(b - a, c - a); }
bool cw(pt a, pt b, pt c) { return dir(a, b, c) < 0; }
bool ccw(pt a, pt b, pt c) { return dir(a, b, c) > 0; }

vector<pair<pt, pt>> seg;
vi res;
int np, ns;

bool between(int x, int l, int r) { return x >= l && x <= r; }

int calc(pt p, int ind) {
    FOR(i, ind, np)
        if(between(p.xx, seg[i].fi.xx, seg[i].se.xx) && ccw(seg[i].fi, seg[i].se, p)) {
            if(res[i] != 1e9) return res[i];
            if(seg[i].fi.yy > seg[i].se.yy)
                return res[i] = calc(seg[i].se, i + 1);
            else
                return res[i] = calc(seg[i].fi, i + 1);
        }
    return p.xx;
}

void solve() {
    cin >> np;

    seg.resize(np);
    F0R(i, np) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        seg[i] = mp(pt(x1, y1), pt(x2, y2));
    }

    sort(ALL(seg), [](pair<pt, pt> a, pair<pt, pt> b) { return mp(a.fi.yy, a.fi.xx) > mp(b.fi.yy, b.fi.xx); });

    res.assign(np, 1e9);
    F0R(i, np) {
        if(res[i] != 1e9) continue;
        if(seg[i].fi.yy > seg[i].se.yy)
            res[i] = calc(seg[i].se, i + 1);
        else
            res[i] = calc(seg[i].fi, i + 1);
    }

    cin >> ns;
    F0R(i, ns) {
        int x, y;
        cin >> x >> y;

        cout << calc(pt(x, y), 0) << endl;
    }

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
        if(tc) cout << endl;
    }
}
