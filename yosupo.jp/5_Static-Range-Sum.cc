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

struct ST {
  int n;
  vector<ll> value, up;
  int inline left(int p) { return p << 1; }
  int inline right(int p) { return (p << 1) + 1; }
  ll build(const vi& a, int p, int L, int R) {
    if (L == R) {
      return value[p] = a[L];
    } else {
      value[p] = build(a, left(p), L, (R + L) / 2) + build(a, right(p), (R + L) / 2 + 1, R);
      return value[p];
    }
  }
  ll query(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return 0;
    if (i <= L && R <= j) return value[p];
    push(p, L, R);
    return query(left(p), L, (L + R) / 2, i, j) + query(right(p), (L + R) / 2 + 1, R, i, j);
  }
  ll add(int p, int L, int R, int i, int j, int val) {
    if (i > R || j < L) return value[p];
    if (L == R) return value[p] += val;
    if (i <= L && R <= j) {
      up[p] += val;
      return value[p] += val;
    }
    push(p, L, R);
    return value[p] = add(left(p), L, (L + R) / 2, i, j, val) + add(right(p), (L + R) / 2 + 1, R, i, j, val);
  }
  void push(int p, int L, int R) {
    if (up[p]) {
      add(left(p), L, (L + R) / 2, L, R, up[p]);
      add(right(p), (L + R) / 2 + 1, R, L, R, up[p]);
      up[p] = 0;
    }
  }
  ST(int n) : n(n), value(n * 4, 0), up(n * 4, 0) {}
  ST(const vi& a) : n(SZ(a)), value(SZ(a) * 4), up(SZ(a) * 4) {
    build(a, 1, 0, SZ(a) - 1);
  }
  ll query(int i, int j) { return query(1, 0, n - 1, i, j); }
  void add(int i, int j, int val) { add(1, 0, n - 1, i, j, val); }
  int size() { return n; }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vi a(n);
    F0R(i, n)
        cin >> a[i];

    ST st(a);

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r-1) << endl;
    }

}

