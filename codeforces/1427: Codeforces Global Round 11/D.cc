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
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (int)(x).size()
#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR (a, 0, (b))
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
#define dout if (DEBUG) cerr
#define dvar(...) " \x1b[35m[" << #__VA_ARGS__ ": " << mt(__VA_ARGS__) << "]\x1b[0m "
template <typename T>
true_type const_iterator_check(typename T::const_iterator*);
template <typename T>
false_type const_iterator_check(...);
template <typename T>
struct IsC : decltype(const_iterator_check<T>(nullptr)) {};
template <>
struct IsC<string> : false_type {};
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

void solve() {
    int n;
    cin >> n;

    vi a(n);
    F0R(i, n) cin >> a[i];

    int currLow = 1;
    int currHigh = 1 + n/2 + n%2;
    int lAmt = 0;
    int rAmt = 0;
    bool turnLow = n % 2;

    vvi res;
    F0R(_, n) {
        int target = turnLow ? currLow : currHigh;

        int pos = -1;
        F0R(i, n) {
            if(a[i] == target) {
                pos = i;
                break;
            }
        }
        assert(pos != -1);

        vi buffers;
        int bufferL = turnLow ? rAmt : lAmt;
        int bufferR = turnLow ? lAmt : rAmt;
        int toPos = pos - bufferL;
        int fromPos = n - pos - bufferR;
        assert(fromPos);

        if(bufferL) buffers.pb(bufferL);
        if(toPos) buffers.pb(toPos);
        buffers.pb(fromPos);
        if(bufferR) buffers.pb(bufferR);

        if(SZ(buffers) > 1)
            res.pb(buffers);

        vi next(n);
        int r = n - 1, p = 0;
        for(int x : buffers) {
            F0R(j, x)
                next[r - x + 1 + j] = a[p++];
            r -= x;
        }
        a = next;

        if(turnLow) {
            lAmt++;
            currLow++;
        } else {
            rAmt++;
            currHigh++;
        }
        turnLow ^= 1;
    }

    cout << SZ(res) << endl;
    for(vi& x : res) {
        cout << SZ(x); 
        for(int y : x)
            cout << ' ' << y;
        cout << endl;
    }
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

