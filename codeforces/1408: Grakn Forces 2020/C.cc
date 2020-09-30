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
#define F0R(a, b) FOR(a, 0, (b))
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
    if (DEBUG) cerr
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
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream&,
                                                             const C&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);
template <typename... T>
using TS = tuple_size<tuple<T...>>;
template <size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, ostream&>::type operator<<(
    ostream& o, const tuple<T...>& t) {
    return o << ", " << get<idx>(t) << ')';
}
template <size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
    return operator<<<idx + 1>(o << ", " << get<idx>(t), t);
}
template <size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, ostream&>::type operator<<(
    ostream& o, const tuple<T...>& t) {
    return operator<<<idx + 1>(o << '(' << get<idx>(t), t);
}
template <typename T>
ostream& operator<<(ostream& o, const tuple<T>& t) {
    return o << get<0>(t);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
    return o << mt(p.fi, p.se);
}
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream& o,
                                                             const C& c) {
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
    int n, l;
    cin >> n >> l;

    vi a(n + 2);
    a[0] = 0;
    FOR(i, 1, n + 1) cin >> a[i];
    a[n + 1] = l;

    vector<double> lTimes(n + 2), rTimes(n + 2);
    FOR(i, 1, n + 2) {
        lTimes[i] = lTimes[i - 1] + 1.0/i*(a[i] - a[i - 1]);
        rTimes[n + 1 - i] = rTimes[n + 1 - i + 1] + 1.0/i*(a[n + 1 - i + 1] - a[n + 1 - i]);
    }


    int indL = 0, indR = n + 1;
    while(indL + 1 < indR) {
        if(abs(lTimes[indL + 1] - rTimes[indR - 1]) < 1e-7) {
            indL++;
            indR--;
        } else if(lTimes[indL + 1] < rTimes[indR - 1]) {
            indL++;
        } else {
            indR--;
        }
    }


    if(indL == indR) {
        cout << setprecision(7) << fixed << lTimes[indL] << endl;
    } else {
        int speedL = indL + 1;
        int speedR = n + 1 - indR + 1;
        double dist = (a[indR] - a[indL]);
        if(lTimes[indL] < rTimes[indR])
            dist -= (rTimes[indR] - lTimes[indL]) * speedL;
        else if(lTimes[indL] > rTimes[indR])
            dist -= (lTimes[indL] - rTimes[indR]) * speedR;

        cout << setprecision(7) << fixed << max(lTimes[indL], rTimes[indR]) + speedL/(1.0*speedL + speedR)*dist/speedL << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc = 1;
    cin >> tc;
    FOR(i, 1, tc + 1) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}

