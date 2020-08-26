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

struct FT2D {
  struct FT {
    vi A;
    int n;
    FT(int n) : A(n + 1, 0), n(n) {}
    int inline LSOne(int i) { return i & (-i); }
    int query(int i) {
      int sum = 0;
      for (; i; i -= LSOne(i)) sum += A[i];
      return sum;
    }
    int query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, int add) {
      for (; i <= n; i += LSOne(i)) A[i] += add;
    }
  };
  vector<FT> fts;
  int n;
  FT2D(int n, int m) : fts(n + 1, FT(m)), n(n) {};
  int inline LSOne(int i) { return i & (-i); }
  int query(int i, int j1, int j2) {
    int sum = 0;
    for (; i; i -= LSOne(i)) sum += fts[i].query(j1, j2);
    return sum;
  }
  int query(int i1, int i2, int j1, int j2) {
    return query(i2, j1, j2) - query(i1 - 1, j1, j2);
  }
  void update(int i, int j, int add) {
    for (; i <= n; i += LSOne(i)) fts[i].update(j, add);
  }
};

void solve() {
    int n;
    cin >> n;

    vi a(n);
    F0R(i, n) cin >> a[i];

    vvi sums(n, vi(n));
    F0R(i, n)
        F0R(j, n) {
            if(i && j) sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            else if(i) sums[i][j] = sums[i - 1][j];
            else if(j) sums[i][j] = sums[i][j - 1];

            if(i < j && a[i] == a[j]) {
                sums[i][j]++;
            }
        }

    tprint(sums, 3);
    ll res = 0;
    F0R(i, n) {
        FOR(j, i + 2, n) {
            if(a[i] != a[j]) continue;
            res += sums[j - 1][n - 1] + sums[i][j] - sums[i][n - 1] - sums[j - 1][j];
        }
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc = 1;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}

