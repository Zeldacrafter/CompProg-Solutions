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

const int INF = 1e9,
      dr[4] = {1, -1, 0, 0},
      dc[4] = {0, 0, 1, -1};
const char d[4] = {'U', 'D', 'L', 'R'};

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    F0R(i, n)
        cin >> a[i];

    vvi dist(n, vi(m, -2));
    queue<pair<ii, int>> q;
    F0R(i, n) F0R(j, m) if(a[i][j] == 'M') {
        q.emplace(mp(i, j), false);
        dist[i][j] = INF;
    }
    F0R(i, n) F0R(j, m) if(a[i][j] == 'A') {
        q.emplace(mp(i, j), true);
        dist[i][j] = 0;
    }


    while(!q.empty()) {
        auto [pos, player] = q.front();
        auto [r, c] = pos;
        q.pop();

        if(dist[r][c] != INF && (!r || !c || r == n - 1 || c == m - 1)) {
            
            cout << "YES\n";
            string res = "";
            while(a[r][c] != 'A') {
                F0R(i, 4) {
                    int rr = r + dr[i];
                    int cc = c + dc[i];

                    if(min(rr, cc) < 0 || rr >= n || cc >= m || dist[rr][cc] != dist[r][c] - 1)
                        continue;

                    res += d[i];
                    r = rr;
                    c = cc;
                }

            }
            reverse(ALL(res));
            cout << SZ(res) << endl << res << endl;

            exit(0);
        }

        F0R(i, 4) {
            int rr = r + dr[i];
            int cc = c + dc[i];

            if(min(rr, cc) < 0 || rr >= n || cc >= m || dist[rr][cc] != -2 || a[rr][cc] == '#')
                continue;
            
            if(player)
                dist[rr][cc] = dist[r][c] + 1;
            else
                dist[rr][cc] = INF;
            q.emplace(mp(rr, cc), player);
        }

    }
    cout << "NO";
    return 0;
}

