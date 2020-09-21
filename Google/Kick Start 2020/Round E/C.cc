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

struct FT {
  vector<ll> A;
  int n;
  FT(int n) : A(n + 1, 0), n(n) {}
  int inline LSOne(int i) { return i & (-i); }
  int query(int i) {
    ll sum = 0;
    for (; i; i -= LSOne(i)) sum += A[i];
    return sum;
  }
  int query(int i, int j) { return query(j) - query(i - 1); }
  void update(int i, int add) {
    for (; i <= n; i += LSOne(i)) A[i] += add;
  }
};

const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<ll> ex(n), rem(n);
    vector<pair<ll, int>> both(n);
    F0R(i, n) {
        cin >> ex[i] >> rem[i];
        both[i] = mp(ex[i] + rem[i], i);
    }

    sort(RALL(both));

    FT ft(n);
    F0R(i, n) ft.update(i + 1, ex[i]);

    ll sum = accumulate(ALL(ex), 0LL);
    ll currBest = INF;

    F0R(i, n)
        if(rem[i] + ex[i] > sum) {
            // We can remove sth
            currBest = sum + ft.query(i);
            break;
        }

    if(currBest == INF) {
        cout << 0 << " INDEFINITELY\n";
        return;
    }

    set<int> q;
    int i = 0;
    while(i < n && both[i].fi > sum)
        q.insert(both[i++].se);

    int removed = 0;
    FOR(rInd, 1, n) {
        int curr = *q.begin();
        q.erase(q.begin());

        ft.update(curr + 1, -ex[curr]);
        sum -= ex[curr];

        while(i < n && both[i].fi > sum)
            q.insert(both[i++].se);

        if(SZ(q)) {
            int next = *q.begin();
            if(ckmax(currBest, sum + ft.query(next)))
                removed = rInd;
        } else {
            currBest = INF;
            removed = rInd;
            break;
        }
    }

    if(currBest == INF)
        cout << removed << " INDEFINITELY\n";
    else
        cout << removed << ' ' << currBest << endl;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc = 1;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
