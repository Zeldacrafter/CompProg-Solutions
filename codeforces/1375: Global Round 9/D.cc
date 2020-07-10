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
#define F0R(a, b) FOR(a, 0, (b))
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
    for (auto& vv : v) {
        for (auto& i : vv) o << setw(width) << i;
        o << endl;
    }
}

int seen[1001];
void solve() {
    memset(seen, 0, sizeof(seen));

    int n;
    cin >> n;

    vi a(n);
    F0R(i, n) {
        cin >> a[i];
        seen[a[i]]++;
    }

    vi res;

    F0R(i, n) {
        if(!seen[i]) {
            res.pb(i);

            int last = a[i];
            a[i] = i;
            seen[i]++;
            --seen[last];
            while(!seen[last] && last < i) {
                res.pb(last);

                int tmp = a[last];
                a[last] = last;
                seen[last]++;
                seen[tmp]--;
                last = tmp;
            }
        }
    }
    //dout << dvar(res) << endl << dvar(a) << endl;

    F0R(i, n) {
        if(a[i] == i) continue;

        FOR(j, i + 1, n) {
            if(a[j] != i) continue;

            res.pb(j);
            int k = 0;
            while(seen[k]) k++;
            seen[k]++;

            seen[a[j]]--;
            a[j] = k;
        }

        //dout << dvar(seen) << dvar(i) << endl;
        //dout << dvar(a) << endl;

        assert(!seen[i]);

        seen[a[i]]--;
        seen[i]++;
        a[i] = i;
        res.pb(i);

    }
    
	dout << dvar(a) << endl;
    assert(SZ(res) <= 2*n);

    cout << SZ(res) << endl;
    for(int x : res) cout << x + 1 << ' ';
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int tt = 1;
    cin >> tt;
    FOR(t, 1, tt + 1) {
        // cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}

