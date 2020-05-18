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
#define F0R(a, b) FOR((a), 0, (b))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define R0F(a, b) ROF((a), (b), -1)
#define CEIL(a, b) ((a) + (b)-1) / (b)
#define SET(a, b) memset((a), (b), sizeof(a))
template <class t>
bool ckmin(t& a, const t& b) {
    return a > b ? a = b, true : false;
}
template <class t>
bool ckmax(t& a, const t& b) {
    return a < b ? a = b, true : false;
}

#ifndef DEBUG
#define DEBUG 0
#endif
#define dout \
    if (DEBUG) std::cerr
#define dvar(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
template <class a, class b>
ostream& operator<<(ostream& o, const pair<a, b>& p);
template <class T>
struct IsC {
    template <class C>
    static char test(typename C::const_iterator*);
    template <class C>
    static int test(...);
    static const bool value = sizeof(test<T>(0)) == sizeof(char);
};
template <>
struct IsC<string> {
    static const bool value = false;
};
template <class C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream& o,
                                                             const C& c) {
    o << '{';
    for (auto it = c.begin(); it != c.end();)
        o << *it << (++it != c.end() ? ", " : "}");
    return o;
}
template <class a, class b>
ostream& operator<<(ostream& o, const pair<a, b>& p) {
    return o << '(' << p.fi << ", " << p.se << ')';
}

int n;
vvi adj;
vi dfsNum, low, a;
int dfsCounter = 0;
int artiDfs(int v, int p = -1) {
  dfsNum[v] = low[v] = dfsCounter++;
  int children = 0;
  bool aP = false;
  for (int u : adj[v]) {
    if (u == p) continue;
    if (dfsNum[u] == -1) {
      ckmin(low[v], artiDfs(u, v));
      if (low[u] >= dfsNum[v] && p != -1 && !aP) {
        a.pb(v);
        aP = true;
      }
      children++;
    } else
      ckmin(low[v], dfsNum[u]);
  }
  if (p == -1 && children > 1) a.pb(v);
  return low[v];
}
void findArtiPoints() {
  dfsNum.assign(SZ(adj), -1);
  low.assign(SZ(adj), -1);
  F0R (v, SZ(adj))
    if (dfsNum[v] == -1) artiDfs(v);
}


int tc;
void solve() {
    map<string, int> toNum;
    map<int, string> toStr;

    F0R(i, n) {
        string s;
        cin >> s;
        toNum[s] = i;
        toStr[i] = s;
    }

    int r;
	cin >> r;
    adj = vvi(n);
    F0R(i, r) {
        string s1, s2;
        cin >> s1 >> s2;
        int i1 = toNum[s1], i2 = toNum[s2];
        adj[i1].pb(i2);
        adj[i2].pb(i1);
    }

    findArtiPoints();

    cout << "City map #" << tc << ": " << SZ(a) << " camera(s) found\n";
    vector<string> res;
    for(int art : a)
        res.pb(toStr[art]);
    sort(ALL(res));
    for(string s : res)
        cout << s << endl;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(tc = 1;;++tc) {
        a.clear();
        dfsNum.clear();
        low.clear();
        dfsCounter = 0;
        cin >> n;
        if(!n) break;
        if(tc > 1) cout << endl;
        solve();
    }
}
