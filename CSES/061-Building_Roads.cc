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

struct DSU {
  DSU(int size) : msize(size), data(size, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int find(int x) {
    return data[x] < 0 ? x : data[x] = find(data[x]);
  }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (data[a] > data[b]) swap(a, b);
    data[a] += data[b], data[b] = a;
    return --msize, true;
  }
  int size() { return msize; }
  int size(int a) { return -data[find(a)]; }
  int msize;
  vi data;
};

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    F0R(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        dsu.join(a, b);
    }

    cout << SZ(dsu) - 1 << endl;

    set<int> found;
    F0R(i, n)
        found.insert(dsu.find(i) + 1);
    
    int curr = -1;
    for(int i : found) {
        if(curr != -1)
            cout << i << ' ' << curr << endl;
        curr = i;
    }

    return 0;
}

